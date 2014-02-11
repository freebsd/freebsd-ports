# $FreeBSD$
#
# MAINTAINER:	ports@FreeBSD.org
#
# Handle the default versions for users chosable multi versions.
#
# It expects users to define DEFAULT_VERSIONS in their make.conf
# Syntax is the following:
#
# DEFAULT_VERSIONS=	perl5=5.18 ruby=2.0

.if !defined(_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
_INCLUDE_BSD_DEFAULT_VERSIONS_MK=	yes

.for lang in ${DEFAULT_VERSIONS}
_l=		${lang:C/=.*//g}
${_l:U}_DEFAULT=	${lang:C/.*=//g}
.endfor

APACHE_DEFAULT?=	2.2
FPC_DEFAULT?=		2.6.2
LUA_DEFAULT?=		5.2
MYSQL_DEFAULT?=		5.5
PERL5_DEFAULT?=		5.16
PGSQL_DEFAULT?=		9.0
PHP_DEFAULT?=		5.4
PYTHON_DEFAULT?=	2.7
PYTHON2_DEFAULT?=	2.7
PYTHON3_DEFAULT?=	3.3
RUBY_DEFAULT?=		1.9
TCLTK_DEFAULT?=		8.6

.endif
