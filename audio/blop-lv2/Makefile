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

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		pkgconfig python:2.7,build tar:bz2 waf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/blop.lv2/*.so

.include <bsd.port.mk>
