# $FreeBSD$

PORTNAME=	waifu2x-w2xc
DISTVERSION=	r6
PORTREVISION=	5
CATEGORIES=	graphics
PKGNAMEPREFIX=	vapoursynth-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Waifu2x (waifu2x-converter-cpp) plugin for VapourSynth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
LIB_DEPENDS=	libw2xc.so:graphics/waifu2x-converter-cpp

USE_GITHUB=	yes
GH_ACCOUNT=	HomeOfVapourSynthEvolution
GH_PROJECT=	VapourSynth-Waifu2x-w2xc

USES=		compiler:c++11-lib gmake localbase pkgconfig
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--install="${STAGEDIR}${DATADIR}" \
		--cxx="${CXX}" \
		--extra-cxxflags="${CPPFLAGS} ${CXXFLAGS}" \
		--extra-ldflags="${LDFLAGS}" \
		--extra-libs="${LIBS}"
MAKEFILE=	GNUmakefile
MAKE_ARGS=	STRIP="${STRIP_CMD}"
DATADIR=	${PREFIX}/lib/vapoursynth
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PORTDATA=	lib${PORTNAME}.so models
PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/\*linux\*/*/' \
		-e 's/-O3 //; /=.*-mfpmath/d; /-msse/d' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/STRIP/s/-x //' ${WRKSRC}/${MAKEFILE}

post-install:
	(cd ${WRKSRC}/Waifu2x-w2xc && ${COPYTREE_SHARE} \
		"${PORTDATA:N*.so}" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
