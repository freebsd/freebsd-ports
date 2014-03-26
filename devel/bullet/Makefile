# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bullet
PORTVERSION=	2.82
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-${SVN_COMMIT}
EXTRACT_SUFX=	.tgz

MAINTAINER=	acm@FreeBSD.org
COMMENT=	3D collision detection and rigid body dynamics library

USE_GL=		gl glu glut
USE_XORG=	x11
#USE_GCC=	any

USES=		cmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-pthread

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-${SVN_COMMIT}

PORTDOCS=	*

SVN_COMMIT=	r2704
.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64") || (${ARCH} == "ia64")
CFLAGS+=	-DUSE_ADDR64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|{OPENGL_glu_LIBRARY}|{OPENGL_glu_LIBRARY} -lcompat|g" ${WRKSRC}/Demos/AllBulletDemos/CMakeLists.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BulletLicense.txt ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}/${DOCSDIR}/CHANGELOG
.endif

.include <bsd.port.post.mk>
