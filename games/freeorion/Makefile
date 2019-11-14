# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeorion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.8
PORTREVISION=	7
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	fd05b34fcc68.patch:-p1
PATCHFILES+=	35863f31210b.patch:-p1
PATCHFILES+=	9313aa4b98cc.patch:-p1
PATCHFILES+=	31d04b0c66d3.patch:-p1 # rebased from f7f9cdeb6cd8
PATCHFILES+=	0318fe967d2b.patch:-p1
PATCHFILES+=	fc4486b30299.patch:-p1
PATCHFILES+=	eff31a5ef564.patch:-p1
PATCHFILES+=	38ce15b0f89c.patch:-p1
PATCHFILES+=	d28d9662bd81.patch:-p1
PATCHFILES+=	78b7a1994b8b.patch:-p1
PATCHFILES+=	ff8c06a6685f.patch:-p1
PATCHFILES+=	4a7b8833cb8d.patch:-p1 # rebased from 7513ede6b03c
PATCHFILES+=	17caf5a174d3.patch:-p1
PATCHFILES+=	5ad3f175925d.patch:-p1

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Turn-based space empire and galactic conquest game

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	multi

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		${PY_BOOST}

USE_GITHUB=	yes

USES=		cmake compiler:c++14-lang python:2.7
LLD_UNSAFE=	yes

PORTDOCS=	ChangeLog.md README.md
PORTDATA=	*

OPTIONS_DEFINE=	DOCS TEST HEADLESS
OPTIONS_SUB=	yes

TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	unittest
TEST_USES=		localbase

HEADLESS_DESC=		Build only headless components: server and AI
HEADLESS_CMAKE_BOOL=	BUILD_HEADLESS
HEADLESS_USES_OFF=	gl openal sdl
HEADLESS_USE_OFF=	SDL=sdl2 GL=gl,glu,glew
HEADLESS_LIB_DEPENDS_OFF= \
		libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
