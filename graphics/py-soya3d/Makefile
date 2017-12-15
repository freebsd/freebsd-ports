# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	soya3d
PORTVERSION=	0.14
PORTREVISION=	14
CATEGORIES=	graphics python
MASTER_SITES=	http://download.gna.org/soya/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Soya-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very high level 3D engine for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR}
LIB_DEPENDS=	libode.so:devel/ode \
		libcal3d.so:graphics/cal3d \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/editobj/editor.py:graphics/py-editobj@${FLAVOR} \
		${PYTHON_SITELIBDIR}/tofu/client.py:net/py-tofu@${FLAVOR} \
		${PYTHON_SITELIBDIR}/cerealizer/__init__.py:security/py-cerealizer@${FLAVOR}

USES=		gmake openal:al,alut python:2.7 tar:bzip2
USE_GL=		glew glu
USE_PYTHON=	autoplist distutils
USE_SDL=	sdl

LDFLAGS+=	-L${LOCALBASE}/lib -lGLU

SOYATUTVER=	0.14

PLIST_FILES=	man/man1/soya_editor.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DISTFILES=	SoyaTutorial-${SOYATUTVER}${EXTRACT_SUFX}

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' -e \
			's|/usr/include|${LOCALBASE}/include|g' ${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/soya/*.so
	${INSTALL_MAN} ${WRKSRC}/manpage/man1/soya_editor.1 ${STAGEDIR}${PREFIX}/man/man1

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/tutorial/* ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${STAGEDIR}${EXAMPLESDIR}/* -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in AUTHORS README
	${INSTALL_DATA} ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
