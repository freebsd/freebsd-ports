# New ports collection makefile for:	p5-DateTime-TimeZone
# Date created:	   4 mai 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-TimeZone
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Time zone object base class and factory

RUN_DEPENDS=	${SITE_PERL}/Class/Singleton.pm:${PORTSDIR}/devel/p5-Class-Singleton \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
