# Created by: vanilla
# $FreeBSD$

PORTNAME=	Color-Calc
PORTVERSION=	1.073
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Color
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Simple calculations with RGB colors

BUILD_DEPENDS=	p5-Graphics-ColorNames-WWW>=1.13:${PORTSDIR}/graphics/p5-Graphics-ColorNames-WWW
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
