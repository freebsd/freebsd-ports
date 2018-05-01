# $FreeBSD$

PORTNAME=	openfx-io
PORTVERSION=	2.3.4
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Set of Readers/Writers plugins written using the OpenFX standard

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libOpenColorIO.so:graphics/opencolorio \
		libIlmImfUtil.so:graphics/OpenEXR \
		libOpenImageIO.so:graphics/openimageio \
		libavformat.so:multimedia/ffmpeg \
		libraw.so:graphics/libraw \
		libSeExpr.so:graphics/seexpr \
		libHalf.so:graphics/ilmbase \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libtiff.so:graphics/tiff \
		libopenjp2.so:graphics/openjpeg

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	MrKepzie
GH_PROJECT=	openfx-io
GH_TAGNAME=	4cc07f9
GH_TUPLE=	devernay:openfx-supportext:d3c4874:openfx_supportext/SupportExt \
		MrKepzie:SequenceParsing:Natron-2.2.0:SequenceParsing/IOSupport/SequenceParsing \
		MrKepzie:tinydir:60f0905:tinydir/IOSupport/SequenceParsing/tinydir \
		devernay:openfx:3056fd6:openfx/openfx

MAKE_ENV+=	CONFIG=release
USE_GL=	gl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/OFX/Plugins|${PREFIX}/OFX/Plugins|g' \
		${WRKSRC}/openfx/Examples/Makefile.master \
		${WRKSRC}/openfx/Support/Plugins/Makefile.master
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}|g' ${WRKSRC}/Makefile.master
	@${REINPLACE_CMD} -e 's|/Contents/$$(ARCH)|/Contents/FreeBSD-x86-64/|g' \
		${WRKSRC}/openfx/Support/Plugins/Makefile.master

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/OFX/Plugins/IO.ofx.bundle/Contents/FreeBSD-x86-64/IO.ofx

.include <bsd.port.mk>
