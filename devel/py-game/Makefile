PORTNAME=	game
DISTVERSION=	2.6.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Module designed to write games in Python
WWW=		https://www.pygame.org/news

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/docs/LGPL.txt

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png
RUN_DEPENDS=	${PYNUMPY} \
		v4l_compat>0:multimedia/v4l_compat

USES=		compiler:c11 jpeg localbase pkgconfig python sdl xorg
USE_SDL=	sdl2 ttf2 image2 mixer2
USE_PYTHON=	autoplist distutils
USE_XORG=	x11

CFLAGS_i386=	-msse2 # src_c/image.c:319:12: error: always_inline function '_mm_set_epi32' requires target feature 'sse2'

SDLNOX11=	sdl-nox11-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-extract:
	@${RM} ${WRKSRC}/examples/.editorconfig

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

#Remove Un-needed macosx files
	@${RM} -r ${WRKSRC}/examples/macosx
	${TAR} -C ${WRKSRC}/examples -cf - . | \
		${TAR} --unlink -C ${STAGEDIR}${EXAMPLESDIR} -xf -

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/docs -cf - . | \
	${TAR} --unlink -C ${STAGEDIR}${DOCSDIR} -xf -

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pygame/*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pygame/_sdl2/*.so

.include <bsd.port.mk>
