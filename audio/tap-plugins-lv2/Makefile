# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	tap-plugins
PORTVERSION=	g20160125
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@rawbw.com
COMMENT=	LV2 port for the TAP (Tom's Audio Processing) plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	moddevices
GH_PROJECT=	tap-lv2
GH_TAGNAME=	de26a3c

post-patch:
	@${REINPLACE_CMD} -e 's| -O3||; s| -Wl,-O1||; s| -fstrength-reduce||; s| -Wl,--strip-all||' \
		${WRKSRC}/Makefile.mk
	@${REINPLACE_CMD} -e 's|^inline$$||' \
		${WRKSRC}/dynamics/tap_dynamics.c

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/lv2/*.lv2/*.so

.include <bsd.port.mk>
