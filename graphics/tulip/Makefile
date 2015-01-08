# Created by: ijliao
# $FreeBSD$

PORTNAME=	tulip
PORTVERSION=	4.6.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System dedicated to the visualization of huge graphs

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libOGDF.so:${PORTSDIR}/math/ogdf \
		libpng.so:${PORTSDIR}/graphics/png \
		libquazip.so:${PORTSDIR}/archivers/quazip \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

USES=		cmake:outsource compiler:c++11-lib dos2unix execinfo python \
		shebangfix
SHEBANG_FILES=	tulip-config.in
DOS2UNIX_FILES=	software/tulip/src/main.cpp
USE_CXXSTD=	c++11
USE_GL=		glew glut
USE_GNOME=	libxml2
USE_QT4=	corelib gui network opengl webkit xml xmlpatterns \
		qmake_build moc_build rcc_build uic_build
CXXFLAGS+=	-fPIC -I${LOCALBASE}/include -DNDEBUG -DOGDF_DLL
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DOGDFLibrary=${LOCALBASE}/lib/libOGDF.so \
		-DOGDFInclude=${LOCALBASE}/include \
		-DBUILD_DOC:BOOL=false
USE_LDCONFIG=	${PREFIX}/lib/tulip

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB+=	TULIP_VERSION=${PORTVERSION} \
		TULIP_VERS=${PORTVERSION:R}

.include <bsd.port.mk>
