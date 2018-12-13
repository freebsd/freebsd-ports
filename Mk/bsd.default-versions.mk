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
#   DEFAULT_VERSIONS=	perl5=5.20 ruby=2.0

.if !defined(_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
_INCLUDE_BSD_DEFAULT_VERSIONS_MK=	yes

LOCALBASE?=	/usr/local

.for lang in APACHE BDB COROSYNC EMACS FIREBIRD FORTRAN FPC GCC GHOSTSCRIPT \
	LINUX LUA MYSQL PERL5 PGSQL PHP PYTHON PYTHON2 PYTHON3 RUBY SSL TCLTK
.if defined(${lang}_DEFAULT)
ERROR+=	"The variable ${lang}_DEFAULT is set and it should only be defined through DEFAULT_VERSIONS+=${lang:tl}=${${lang}_DEFAULT} in /etc/make.conf"
.endif
#.undef ${lang}_DEFAULT
.endfor

.for lang in ${DEFAULT_VERSIONS}
_l=		${lang:C/=.*//g}
${_l:tu}_DEFAULT=	${lang:C/.*=//g}
.endfor

# Possible values: 2.2, 2.4
APACHE_DEFAULT?=	2.4
# Possible values: 48, 5, 6
BDB_DEFAULT?=		5
# Possible values: 2, 3
COROSYNC_DEFAULT?=	2
# Possible_values: full canna nox devel_full devel_nox
#EMACS_DEFAULT?=	let the flavor be the default if not explicitly set
# Possible values: 2.5
FIREBIRD_DEFAULT?=	2.5
# Possible values: flang (experimental), gfortran
FORTRAN_DEFAULT?=	gfortran
# Possible values: 3.0.4
FPC_DEFAULT?=		3.0.4
# Possible values: 50, 60, 70 (to be used when non-base compiler is required)
LLVM_DEFAULT?=		70
# Possible values: 5, 6, 7, 8
GCC_DEFAULT?=		8
# Possible values: 7, 8, 9, agpl
GHOSTSCRIPT_DEFAULT?=	agpl
# Possible values: 1.8.4
LAZARUS_DEFAULT?=	1.8.4
.if ${ARCH} == amd64
# Possible values: c6, c6_64, c7
LINUX_DEFAULT?=		c6_64
.else
# Possible values: c6
LINUX_DEFAULT?=		c6
.endif
# Possible values: 5.1, 5.2, 5.3
LUA_DEFAULT?=		5.2
# Possible values: 5.5, 5.6, 5.7, 8.0, 5.5m, 10.0m, 10.1m, 10.2m, 10.3m, 5.5p, 5.6p, 5.7p, 5.6w
MYSQL_DEFAULT?=		5.6
# Possible values: 5.24, 5.26, 5.28, devel
.if !exists(${LOCALBASE}/bin/perl) || (!defined(_PORTS_ENV_CHECK) && \
    defined(PACKAGE_BUILDING))
PERL5_DEFAULT?=		5.28
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
# Possible values: 9.3, 9.4, 9.5, 9.6, 10, 11
PGSQL_DEFAULT?=		9.5
# Possible values: 5.6, 7.1, 7.2, 7.3
PHP_DEFAULT?=		7.2
# Possible values: 2.7, 3.4, 3.5, 3.6, 3.7
PYTHON_DEFAULT?=	2.7
# Possible values: 2.7
PYTHON2_DEFAULT?=	2.7
# Possible values: 3.4, 3.5, 3.6, 3.7
PYTHON3_DEFAULT?=	3.6
# Possible values: 2.3, 2.4, 2.5
RUBY_DEFAULT?=		2.4
# Possible values: 4.6, 4.7, 4.8
SAMBA_DEFAULT?=		4.7
# Possible values: base, openssl, openssl111, libressl, libressl-devel
.if !defined(SSL_DEFAULT)
#	If no preference was set, check for an installed base version
#	but give an installed port preference over it.
.  if	!defined(SSL_DEFAULT) && \
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
# Possible values: 8.5, 8.6, 8.7
TCLTK_DEFAULT?=		8.6

# Possible values: 4, 5, 6
VARNISH_DEFAULT?=	4

.endif
