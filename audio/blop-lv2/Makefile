# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	blop-lv2
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bandlimited oscillator plugins for LV2-aware audio applications

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		waf pkgconfig tar:bz2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/blop.lv2/*.so

.include <bsd.port.mk>
