# $FreeBSD$
#
# MAINTAINER:	ports@FreeBSD.org
#
# Provide default versions for ports with multiple versions selectable
# by the user.
#
# Users who want to override these defaults can easily do so by defining
# DEFAULT_VERSIONS in their make.conf as follows:
#
#   DEFAULT_VERSIONS=	perl5=5.18 ruby=2.0

.if !defined(_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
_INCLUDE_BSD_DEFAULT_VERSIONS_MK=	yes

LOCALBASE?=	/usr/local

.for lang in ${DEFAULT_VERSIONS}
_l=		${lang:C/=.*//g}
${_l:tu}_DEFAULT=	${lang:C/.*=//g}
.endfor

# Possible values: 2.2, 2.4
APACHE_DEFAULT?=	2.4
# Possible values: 48, 5, 6
BDB_DEFAULT?=		5
# Possible values: 2.5
FIREBIRD_DEFAULT?=	2.5
# Possible values: 3.0.0
FPC_DEFAULT?=		3.0.0
# Possible values: 4.6, 4.7, 4.8, 4.9, 5
GCC_DEFAULT?=		4.8
# Possible values: 7, 8, 9, agpl
GHOSTSCRIPT_DEFAULT?=	agpl
# Possible values: 5.1, 5.2, 5.3
LUA_DEFAULT?=		5.2
# Possible values: 5.1, 5.5, 5.6, 5.7, 5.5m, 10.0m, 10.1m, 5.5p, 5.6p
MYSQL_DEFAULT?=		5.6
# Possible values: 5.18, 5.20, 5.22, devel
.if !exists(${LOCALBASE}/bin/perl) || (!defined(_PORTS_ENV_CHECK) && \
    defined(PACKAGE_BUILDING))
PERL5_DEFAULT?=		5.20
.elif !defined(PERL5_DEFAULT)
# There's no need to replace development versions, like "5.23" with "devel"
# because 1) nobody is supposed to use it outside of poudriere, and 2) it must
# be set manually in /etc/make.conf in the first place, and we're never getting
# in here.
.if !defined(_PERL5_FROM_BIN)
_PERL5_FROM_BIN!=	perl -e 'printf "%vd\n", $$^V;'
.endif
_EXPORTED_VARS+=	_PERL5_FROM_BIN
PERL5_DEFAULT:=		${_PERL5_FROM_BIN:R}
.endif
# Possible values: 9.1, 9.2, 9.3, 9.4, 9.5
PGSQL_DEFAULT?=		9.3
# Possible values: 5.5, 5.6, 7.0
PHP_DEFAULT?=		5.6
# Possible values: 2.7, 3.3, 3.4, 3.5
PYTHON_DEFAULT?=	2.7
# Possible values: 2.7
PYTHON2_DEFAULT?=	2.7
# Possible values: 3.3, 3.4, 3.5
PYTHON3_DEFAULT?=	3.4
# Possible values: 2.0, 2.1, 2.2, 2.3
RUBY_DEFAULT?=		2.2
# Possible values: base, openssl, openssl-devel, libressl, libressl-devel
.if !defined(SSL_DEFAULT)
#	If no preference was set, check for an installed base version
#	but give an installed port preference over it.
.  if defined(WITH_OPENSSL_PORT)
.    if defined(OPENSSL_PORT)
SSL_DEFAULT:=${OPENSSL_PORT:T}
WARNING+=	"Using WITH_OPENSSL_PORT and OPENSSL_PORT in make.conf is deprecated, replace them with DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT} in your make.conf"
.    else
SSL_DEFAULT=openssl
WARNING+=	"Using WITH_OPENSSL_PORT in make.conf is deprecated, replace it with DEFAULT_VERSIONS+=ssl=openssl in your make.conf"
.    endif
.  elif defined(WITH_OPENSSL_BASE)
SSL_DEFAULT=base
WARNING+=	"Using WITH_OPENSSL_BASE in make.conf is deprecated, replace it with DEFAULT_VERSIONS+=ssl=base in your make.conf"
.  elif	!defined(WITH_OPENSSL_BASE) && \
	!defined(WITH_OPENSSL_PORT) && \
	!defined(SSL_DEFAULT) && \
	!exists(${DESTDIR}/${LOCALBASE}/lib/libcrypto.so) && \
	exists(${DESTDIR}/usr/include/openssl/opensslv.h)
SSL_DEFAULT=	base
.  else
.    if exists(${DESTDIR}/${LOCALBASE}/lib/libcrypto.so)
.      if defined(PKG_BIN)
# find installed port and use it for dependency
.        if !defined(OPENSSL_INSTALLED)
.          if defined(DESTDIR)
PKGARGS=	-c ${DESTDIR}
.          else
PKGARGS=
.          endif
OPENSSL_INSTALLED!=	${PKG_BIN} ${PKGARGS} which -qo ${LOCALBASE}/lib/libcrypto.so || :
.        endif
.        if defined(OPENSSL_INSTALLED) && !empty(OPENSSL_INSTALLED)
SSL_DEFAULT:=		${OPENSSL_INSTALLED:T}
WARNING+=	"You have ${OPENSSL_INSTALLED} installed but do not have DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT} set in your make.conf"
.        endif
.      else
check-makevars::
	@${ECHO_MSG} "You have a ${LOCALBASE}/lib/libcrypto.so file installed, but the framework is unable"
	@${ECHO_MSG} "to determine what port it comes from."
	@${ECHO_MSG} "Add DEFAULT_VERSIONS+=ssl=<openssl package name> to your /etc/make.conf and try again."
	@${FALSE}
.      endif
.    endif
.  endif
# Make sure we have a default in the end
SSL_DEFAULT?=	base
.endif
# Possible values: 8.4, 8.5, 8.6
TCLTK_DEFAULT?=		8.6

# Version of lang/gcc.  Do not override!
LANG_GCC_IS=		4.8

.endif
