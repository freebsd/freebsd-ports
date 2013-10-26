# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glfw
PORTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Portable framework for OpenGL development

LICENSE=	ZLIB

USES=		cmake
USE_XORG=	xi xrandr
USE_GL=		glu
USE_LDCONFIG=	yes
USE_GCC=	4.6+

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.md

DOCSRCDIR2=	${WRKSRC}/docs/html/search
DOCSDIR2=	${DOCSDIR}/docs/html/search
DOC_FILES2=	*

DOCSRCDIR3=	${WRKSRC}/docs/html
DOCSDIR3=	${DOCSDIR}/docs/html
DOC_FILES3=	*.html *.png *.css *.js

PORTEXAMPLES=	*

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

EXAMPLESSRCDIR1=	${WRKSRC}/examples
EXAMPLES_FILES1=	boing gears heightmap simple splitview wave

EXAMPLESSRCDIR2=	${WRKSRC}/tests
EXAMPLESDIR2=		${EXAMPLESDIR}/tests
EXAMPLES_FILES2=	accuracy clipboard defaults events fsaa  gamma glfwinfo iconify \
			joysticks modes peter reopen sharing tearing threads title windows

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES1:S|^|${EXAMPLESSRCDIR1}/|} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR2}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES2:S|^|${EXAMPLESSRCDIR2}/|} ${STAGEDIR}${EXAMPLESDIR2}

.include <bsd.port.mk>
