# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	tap-plugins
DISTVERSION=	g20180220
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 port for the TAP (Tom's Audio Processing) plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	moddevices
GH_PROJECT=	tap-lv2
GH_TAGNAME=	cab6e0d

MAKE_ENV+=	NOOPT=true

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/lv2/*.lv2/*.so

.include <bsd.port.mk>
