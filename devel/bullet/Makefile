# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bullet
PORTVERSION=	2.82
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	3D collision detection and rigid body dynamics library

LICENSE=	ZLIB

USE_GITHUB=	yes
GH_ACCOUNT=	bulletphysics
GH_PROJECT=	bullet3

USE_GL=		gl glu glut
USE_XORG=	x11

USES=		cmake tar:tgz
CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON

CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|{OPENGL_glu_LIBRARY}|{OPENGL_glu_LIBRARY} -lcompat|g" ${WRKSRC}/Demos/AllBulletDemos/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BulletLicense.txt ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}/${DOCSDIR}/CHANGELOG

.include <bsd.port.mk>
