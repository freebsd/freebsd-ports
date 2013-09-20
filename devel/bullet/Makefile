# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bullet
PORTVERSION=	2.77
CATEGORIES=	devel
PORTREVISION=	1
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	acm@FreeBSD.org
COMMENT=	3D collision detection and rigid body dynamics library

USE_GL=		gl glu glut
USE_XORG=	x11
USE_GCC=	any

USES=		cmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-pthread

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64") || (${ARCH} == "ia64")
CFLAGS+=	-DUSE_ADDR64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|{OPENGL_glu_LIBRARY}|{OPENGL_glu_LIBRARY} -lcompat|g" ${WRKSRC}/Demos/AllBulletDemos/CMakeLists.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}/CHANGELOG
.endif

.include <bsd.port.post.mk>
