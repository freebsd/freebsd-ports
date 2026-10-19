PORTNAME=	openfx-arena
PORTVERSION=	2.5.0
DISTVERSIONPREFIX=	Natron-
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Extra OpenFX plugins for Natron
WWW=		https://github.com/NatronGitHub/openfx-arena

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le
BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio \
		libfontconfig.so:x11-fonts/fontconfig \
		libcdr-0.1.so:graphics/libcdr01 \
		librevenge-0.0.so:textproc/librevenge \
		libpoppler-glib.so:graphics/poppler-glib \
		liblcms2.so:graphics/lcms2 \
		libzip.so:archivers/libzip \
		libpoppler.so:graphics/poppler

USES=		compiler:c++20-lang gl gmake gnome iconv magick:6 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_TUPLE=	NatronGitHub:openfx-supportext:8aff0b0:openfx_supportext/SupportExt \
		NatronGitHub:openfx:a5d9ca8:openfx/OpenFX \
		NatronGitHub:openfx-io:d4c9612:OpenFX_IO/OpenFX-IO \
		lvandeve:lodepng:997936f:dummy/lodepng \
		NatronGitHub:SequenceParsing:3c93fcc:SequenceParsing/OpenFX-IO/IOSupport/SequenceParsing \
		NatronGitHub:tinydir:64fb1d4:tinydir/OpenFX-IO/IOSupport/SequenceParsing/tinydir

MAKE_ENV+=	CONFIG=release \
		CXXFLAGS_EXTRA=-std=c++20
USE_GL=	gl
USE_GNOME=	libxml2 pango cairo librsvg2
USE_XORG+=	x11 xcb xau xdamage xfixes xft xxf86vm xrender xext xdmcp pixman sm ice xt

post-extract:
	@${RMDIR} ${WRKSRC}/OpenFX-IO/openfx
	${LN} -s ../OpenFX ${WRKSRC}/OpenFX-IO/openfx

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/OFX/Plugins|${PREFIX}/OFX/Plugins|g' \
		${WRKSRC}/OpenFX/Examples/Makefile.master \
		${WRKSRC}/OpenFX/Support/Plugins/Makefile.master \
		${WRKSRC}/OpenFX/HostSupport/src/ofxhPluginCache.cpp
	@${REINPLACE_CMD} -e 's|/Contents/$$(ARCH)|/Contents/FreeBSD-x86-64/|g' \
		-e 's|-L/usr/local/lib -shared|-L/usr/local/lib -Wl,--as-needed -shared|' \
		${WRKSRC}/OpenFX/Support/Plugins/Makefile.master
post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/OFX/Plugins/Arena.ofx.bundle/Contents/FreeBSD-x86-64/Arena.ofx

.include <bsd.port.mk>
