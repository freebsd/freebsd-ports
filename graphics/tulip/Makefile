# Created by: ijliao
# $FreeBSD$

PORTNAME=	tulip
PORTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	System dedicated to the visualization of huge graphs

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libQxtCore.so:${PORTSDIR}/devel/libqxt \
		libOGDF.so:${PORTSDIR}/math/ogdf \
		libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

USES=		cmake:outsource compiler:c++11-lib shebangfix dos2unix
SHEBANG_FILES=	tulip-config.in
DOS2UNIX_FILES=	software/tulip/src/main.cpp
USE_CXXSTD=	c++11
USE_GL=		glew glut
USE_GNOME=	libxml2
USE_PYTHON=	yes
USE_QT4=	corelib moc_build uic_build rcc_build gui opengl xml network qmake_build \
		designer assistant assistantclient
CXXFLAGS+=	-fPIC -I${LOCALBASE}/include -DNDEBUG -DOGDF_DLL
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-DPYTHON_INCLUDEDIR:PATH=${PYTHON_INCLUDEDIR} \
    		-DLOCALBASE:PATH=${LOCALBASE} \
		-DOGDFLibrary=${LOCALBASE}/lib/libOGDF.so \
		-DOGDFInclude=${LOCALBASE}/include
USE_LDCONFIG=	${PREFIX}/lib/tulip

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB+=	TULIP_VERSION=${PORTVERSION} \
		TULIP_VERS=${PORTVERSION:R}

.include <bsd.port.mk>
