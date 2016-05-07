# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	soya3d
PORTVERSION=	0.14
PORTREVISION=	11
CATEGORIES=	graphics python
MASTER_SITES=	http://download.gna.org/soya/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Soya-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very high level 3D engine for Python

BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:devel/ode \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow
LIB_DEPENDS=	libcal3d.so:graphics/cal3d \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/editobj/editor.py:graphics/py-editobj \
		${PYTHON_SITELIBDIR}/tofu/client.py:net/py-tofu \
		${PYTHON_SITELIBDIR}/cerealizer/__init__.py:security/py-cerealizer

USES=		gmake openal:al,alut python tar:bzip2
USE_GL=		glew glu
USE_PYTHON=	autoplist distutils
USE_SDL=	sdl

LDFLAGS+=	-L${LOCALBASE}/lib -lGLU

SOYATUTVER=	0.14

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	man/man1/soya_editor.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
DISTFILES+=	SoyaTutorial-${SOYATUTVER}${EXTRACT_SUFX}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS	+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' -e \
			's|/usr/include|${LOCALBASE}/include|g' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/soya/*.so
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/tutorial/* ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${STAGEDIR}${EXAMPLESDIR}/* -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for FILE in AUTHORS README
	@${INSTALL_DATA} ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/${FILE} ${STAGEDIR}${DOCSDIR}
. endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/manpage/man1/soya_editor.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>
