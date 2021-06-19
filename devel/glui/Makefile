# Created by: mwest@uct.ac.za

PORTNAME=	glui
PORTVERSION=	2.36
PORTREVISION=	6
CATEGORIES=	devel graphics
MASTER_SITES=	SF/${PORTNAME}/Source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GLUT-based C++ user interface library

USES=		gl gmake tar:tgz xorg
USE_GL=		glut
USE_XORG=	xmu xext x11 xi
USE_LDCONFIG=	yes

MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	include/glui.h lib/libglui.a lib/libglui.so lib/libglui.so.0
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/GL/glui.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libglui.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libglui.so \
		${STAGEDIR}${PREFIX}/lib/libglui.so.0
	${LN} -s libglui.so.0 ${STAGEDIR}${PREFIX}/lib/libglui.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/glui_manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
