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

.for lang in ${DEFAULT_VERSIONS}
_l=		${lang:C/=.*//g}
${_l:tu}_DEFAULT=	${lang:C/.*=//g}
.endfor

APACHE_DEFAULT?=	2.4
FPC_DEFAULT?=		2.6.4
GCC_DEFAULT?=		4.8
LUA_DEFAULT?=		5.2
MYSQL_DEFAULT?=		5.6
.if !defined(_PORTS_ENV_CHECK) && \
    (defined(PACKAGE_BUILDING) || !exists(${LOCALBASE}/bin/perl))
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
PGSQL_DEFAULT?=		9.3
PHP_DEFAULT?=		5.6
PYTHON_DEFAULT?=	2.7
PYTHON2_DEFAULT?=	2.7
PYTHON3_DEFAULT?=	3.4
RUBY_DEFAULT?=		2.1
TCLTK_DEFAULT?=		8.6
FIREBIRD_DEFAULT?=	2.5
GHOSTSCRIPT_DEFAULT?=	9

# Version of lang/gcc.  Do not override!
LANG_GCC_IS=		4.8

.endif
