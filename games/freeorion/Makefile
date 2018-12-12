# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeorion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.8
PORTREVISION=	3
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	fd05b34fcc68.patch:-p1
PATCHFILES+=	35863f31210b.patch:-p1
PATCHFILES+=	9313aa4b98cc.patch:-p1

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
HEADLESS_USES_OFF=	openal
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
