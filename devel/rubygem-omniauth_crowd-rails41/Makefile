# $FreeBSD$

PKGNAMESUFFIX=	-rails41

RUN_DEPENDS=	rubygem-activesupport41>=0:${PORTSDIR}/devel/rubygem-activesupport41 \
		rubygem-nokogiri>=1.4.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-omniauth>=1.0:${PORTSDIR}/security/rubygem-omniauth

MASTERDIR=	${.CURDIR}/../rubygem-omniauth_crowd

.include "${MASTERDIR}/Makefile"
