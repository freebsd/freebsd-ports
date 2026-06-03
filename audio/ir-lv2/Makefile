PORTNAME=	ir
DISTVERSION=	1.4.0
CATEGORIES=	audio
MASTER_SITES=	https://git.hq.sig7.se/ir.lv2.git/snapshot/${IR_COMMIT}?dummy=/
PKGNAMESUFFIX=	-lv2
DISTNAME=	ir.lv2-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 impulse response plugin for reverb and cabinet simulation
WWW=		https://tomscii.sig7.se/plugins/ir.lv2/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libzita-convolver.so:audio/zita-convolver \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake gnome pkgconfig
USE_GNOME=	glib20 gtk20 gdkpixbuf cairo

MAKE_ENV=	INSTDIR=${STAGEDIR}${PREFIX}/lib/lv2
WRKSRC=		${WRKDIR}/ir.lv2-${IR_COMMIT:C/^(.......).*/\1/}

IR_COMMIT=	1d4a4f9b1aad6223d541ebb0c16d85d527478222

PLIST_FILES=	lib/lv2/ir.lv2/ir.so lib/lv2/ir.lv2/ir.ttl \
		lib/lv2/ir.lv2/ir_gui.so lib/lv2/ir.lv2/manifest.ttl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/ir.lv2/ir*.so

.include <bsd.port.mk>
