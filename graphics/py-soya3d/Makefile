# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	soya3d
PORTVERSION=	0.14
PORTREVISION=	8
CATEGORIES=	graphics python
MASTER_SITES=	http://download.gna.org/soya/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Soya-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very high level 3D engine for Python

BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	libcal3d.so:${PORTSDIR}/graphics/cal3d \
		libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/editobj/editor.py:${PORTSDIR}/graphics/py-editobj \
		${PYTHON_SITELIBDIR}/tofu/client.py:${PORTSDIR}/net/py-tofu \
		${PYTHON_SITELIBDIR}/cerealizer/__init__.py:${PORTSDIR}/security/py-cerealizer

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USES=		gmake openal:al,alut tar:bzip2
USE_GL=		glew glu
USE_SDL=	sdl

LDFLAGS+=	-L${LOCALBASE}/lib -lGLU

MANDIR=	${WRKDIR}/${DISTNAME}/manpage/man1
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
SOYATUTVER=	0.14

OPTIONS_DEFINE=	DOCS EXAMPLES

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
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/tutorial/* ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${STAGEDIR}${EXAMPLESDIR}/* -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in AUTHORS README
	@${INSTALL_DATA} ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.for FILE in ${MAN1}
	${INSTALL_MAN} ${MANDIR}/${FILE} ${STAGEDIR}${PREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
