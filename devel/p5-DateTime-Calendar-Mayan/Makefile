# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Calendar-Mayan
PORTVERSION=	0.06.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mayan Long Count, Haab, and Tzolkin calendars

RUN_DEPENDS=	p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-DateTime>=0:devel/p5-DateTime
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
