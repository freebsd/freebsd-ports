PORTNAME=	openfx-arena
PORTVERSION=	2.4.3
DISTVERSIONPREFIX=	Natron-
PORTREVISION=	21
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Extra OpenFX plugins for Natron
WWW=		https://github.com/NatronGitHub/openfx-arena

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le
BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi \
		libcdr-0.1.so:graphics/libcdr01 \
		librevenge-0.0.so:textproc/librevenge \
		libpoppler-glib.so:graphics/poppler-glib \
		liblcms2.so:graphics/lcms2 \
		libzip.so:archivers/libzip \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libpcre.so:devel/pcre \
		libffi.so:devel/libffi \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libharfbuzz.so:print/harfbuzz \
		libgraphite2.so:graphics/graphite2 \
		libicui18n.so:devel/icu \
		liblqr-1.so:graphics/liblqr-1 \
		libfftw3.so:math/fftw3 \
		libltdl.so:devel/libltdl \
		libpoppler.so:graphics/poppler \
		libraqm.so:print/libraqm

USES=		compiler:c++20-lang gl gmake gnome iconv magick:6 ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_TUPLE=	NatronGitHub:openfx-supportext:79d8c22:openfx_supportext/SupportExt \
		NatronGitHub:openfx:d5db5d0:openfx/OpenFX \
		NatronGitHub:openfx-io:c6ad47b:OpenFX_IO/OpenFX-IO \
		lvandeve:lodepng:5601b82:dummy/lodepng \
		NatronGitHub:SequenceParsing:3c93fcc:SequenceParsing/OpenFX-IO/IOSupport/SequenceParsing \
		NatronGitHub:tinydir:64fb1d4:tinydir/OpenFX-IO/IOSupport/SequenceParsing/tinydir

MAKE_ENV+=	CONFIG=release
USE_GL=	gl
USE_GNOME=	libxml2 pango cairo librsvg2
USE_XORG+=	x11 xcb xau xdamage xfixes xft xxf86vm xrender xext xdmcp pixman sm ice xt
MAKE_ENV+=	CONFIG=release

post-extract:
	@${RMDIR} ${WRKSRC}/OpenFX-IO/openfx
	${LN} -s ../OpenFX ${WRKSRC}/OpenFX-IO/openfx

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/OFX/Plugins|${PREFIX}/OFX/Plugins|g' \
		${WRKSRC}/OpenFX/Examples/Makefile.master \
		${WRKSRC}/OpenFX/Support/Plugins/Makefile.master \
		${WRKSRC}/OpenFX/HostSupport/src/ofxhPluginCache.cpp
	@${REINPLACE_CMD} -e 's|/Contents/$$(ARCH)|/Contents/FreeBSD-x86-64/|g' \
		${WRKSRC}/OpenFX/Support/Plugins/Makefile.master
post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/OFX/Plugins/Arena.ofx.bundle/Contents/FreeBSD-x86-64/Arena.ofx

.include <bsd.port.mk>
