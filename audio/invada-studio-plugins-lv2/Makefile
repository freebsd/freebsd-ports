PORTNAME=	invada-studio-plugins
DISTVERSIONPREFIX=	lv2_
DISTVERSION=	1.2.0
DISTVERSIONSUFFIX=	-nopkg
CATEGORIES=	audio
MASTER_SITES=	https://launchpad.net/invada-studio/lv2/1.2/+download/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 audio effect plugins, ported from VST

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake gnome localbase pkgconfig tar:tgz
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20
LLD_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/*/*.so

.include <bsd.port.mk>
