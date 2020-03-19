# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeorion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.9
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Turn-based space empire and galactic conquest game

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	multi

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		${PY_BOOST}

USE_GITHUB=	yes

USES=		cmake compiler:c++14-lang python:2.7

LDFLAGS_i386=	-Wl,-znotext

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
