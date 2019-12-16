# $FreeBSD$

PORTNAME=	waifu2x-w2xc
DISTVERSION=	r8
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

USES=		compiler:c++14-lang localbase:ldflags meson pkgconfig
DATADIR=	${PREFIX}/lib/vapoursynth
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PORTDATA=	lib${PORTNAME}.so models
PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

post-patch:
# FreeBSD i386 defaults to -march=i686 (i486 with Clang < 9)
	@${REINPLACE_CMD} '/-msse2/d' ${WRKSRC}/meson.build

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
