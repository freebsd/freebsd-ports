# $FreeBSD$

PORTNAME=	eq10q
DISTVERSION=	2.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parametric equalizer LV2 audio plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to compile: unknown FP unit 'sse'
BROKEN_armv6=		fails to compile: unknown FP unit 'sse'
BROKEN_armv7=		fails to compile: unknown FP unit 'sse'
BROKEN_mips64=		fails to compile: unknown FP unit 'sse'

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake:outsource dos2unix localbase:ldflags pkgconfig
USE_GNOME=	glib20 gtk20 gtkmm24 gdkpixbuf2 atkmm cairo cairomm pangomm
DOS2UNIX_FILES=	dsp/vu.h

post-patch:
	@${REINPLACE_CMD} -e 's/pow10(/pow(10,/g' \
		${WRKSRC}/gui/widgets/*.cpp

.include <bsd.port.mk>
