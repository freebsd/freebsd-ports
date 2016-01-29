# $FreeBSD$

PKGNAMESUFFIX=	-rails41

DEPRECATED=	Rails 4.1 is no longer supported - please switch to Rails 4.2
EXPIRATION_DATE=	2016-03-31

RUN_DEPENDS=	rubygem-activesupport41>=0:${PORTSDIR}/devel/rubygem-activesupport41 \
		rubygem-nokogiri>=1.4.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-omniauth>=1.0:${PORTSDIR}/security/rubygem-omniauth

MASTERDIR=	${.CURDIR}/../rubygem-omniauth_crowd

.include "${MASTERDIR}/Makefile"
