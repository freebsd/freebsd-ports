# $FreeBSD$

PORTNAME=	openfx-arena
PORTVERSION=	2.3.14
DISTVERSIONPREFIX=	Natron-
PORTREVISION=	15
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Extra OpenFX plugins for Natron

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64
BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio \
		libfontconfig.so:x11-fonts/fontconfig \
		libcdr-0.1.so:graphics/libcdr01 \
		librevenge-0.0.so:textproc/librevenge \
		libpoppler-glib.so:graphics/poppler-glib \
		liblcms2.so:graphics/lcms2 \
		libMagick++-6.so:graphics/ImageMagick6 \
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
		libpoppler.so:graphics/poppler

USES=		gl gmake gnome iconv xorg
USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_PROJECT=	openfx-arena
GH_TUPLE=	NatronGitHub:openfx-supportext:e600cae:openfx_supportext/SupportExt \
		NatronGitHub:openfx:a85dc34:openfx/OpenFX \
		NatronGitHub:openfx-io:Natron-2.3.12:OpenFX_IO/OpenFX-IO \
		NatronGitHub:SequenceParsing:9e8b77a:SequenceParsing/OpenFX-IO/IOSupport/SequenceParsing \
		NatronGitHub:tinydir:3aae922:tinydir/OpenFX-IO/IOSupport/SequenceParsing/tinydir

MAKE_ENV+=	CONFIG=release
USE_GL=	gl
USE_GNOME=	libxml2 pango cairo librsvg2
USE_XORG+=	x11 xcb xau xdamage xfixes xxf86vm xrender xext xdmcp pixman sm ice xt
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
