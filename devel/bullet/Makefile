# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bullet
PORTVERSION=	2.82
PORTREVISION=	2
CATEGORIES=	devel
PORTREVISION=	1
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-${SVN_COMMIT}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	3D collision detection and rigid body dynamics library

LICENSE=	ZLIB

USE_GL=		gl glu glut
USE_XORG=	x11

USES=		cmake tar:tgz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-pthread

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-${SVN_COMMIT}

PORTDOCS=	*

SVN_COMMIT=	r2704

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64") || (${ARCH} == "ia64")
CFLAGS+=	-DUSE_ADDR64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|{OPENGL_glu_LIBRARY}|{OPENGL_glu_LIBRARY} -lcompat|g" ${WRKSRC}/Demos/AllBulletDemos/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BulletLicense.txt ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}/${DOCSDIR}/CHANGELOG

.include <bsd.port.post.mk>
