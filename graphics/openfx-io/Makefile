# $FreeBSD$

PORTNAME=	openfx-io
PORTVERSION=	2.3.14
DISTVERSIONPREFIX=	Natron-
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Set of Readers/Writers plugins written using the OpenFX standard

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libOpenColorIO.so:graphics/opencolorio \
		libIlmImfUtil.so:graphics/openexr \
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
GH_ACCOUNT=	NatronGitHub
GH_PROJECT=	openfx-io
GH_TUPLE=	NatronGitHub:openfx:a85dc34:openfx/openfx \
		NatronGitHub:SequenceParsing:9e8b77a:SequenceParsing/IOSupport/SequenceParsing \
		NatronGitHub:tinydir:3aae922:tinydir/IOSupport/SequenceParsing/tinydir \
		NatronGitHub:openfx-supportext:e600cae:openfx_supportext/SupportExt

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
