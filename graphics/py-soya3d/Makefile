# New ports collection makefile for:	py-soya3d
# Date created:				2005-10-04
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	soya3d
PORTVERSION=	0.10.4
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/soya/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Soya-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	python

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Very high level 3D engine for Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/_openal.so:${PORTSDIR}/audio/py-openal \
		${PYTHON_SITELIBDIR}/pysdl_mixer/sdl_mixer.so:${PORTSDIR}/audio/py-sdl_mixer \
		pyrexc:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	cal3d.11:${PORTSDIR}/graphics/cal3d \
		GLEW.1:${PORTSDIR}/graphics/glew \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/editobj/editor.py:${PORTSDIR}/graphics/py-editobj \
		${PYTHON_SITELIBDIR}/tofu/client.py:${PORTSDIR}/net/py-tofu

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GL=		yes
USE_GMAKE=	yes

MANDIR=	${WRKDIR}/${DISTNAME}/manpage/man1
MAN1=	soya_editor.1
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
SOYATUTVER=	0.10.2

.if !defined(NOPORTDOCS)
DISTFILES+=	SoyaTutorial-${SOYATUTVER}${EXTRACT_SUFX}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|g' \
		${WRKSRC}/ode-0.5/configurator.c
	@${REINPLACE_CMD} -e \
		's|g++|${CXX}|; \
		s|-Wall||g; \
		s|-L/usr/X11/lib|-lXext|; \
		s|-L/usr/lib/X11R6||; \
		s|-L/usr/lib/X11||; \
		s|-L/usr/X11R6/lib|-L${X11BASE}/lib|; \
		s|-fno-rtti||; \
		s|-ffast-math|${CXXFLAGS} -I${X11BASE}/include|' \
		${WRKSRC}/ode-0.5/config/makefile.unix-gcc
	@${REINPLACE_CMD} -e \
		's|^BUILD=debug|#BUILD=debug|; \
		s|^#BUILD=release|BUILD=release|' \
		${WRKSRC}/ode-0.5/config/user-settings

post-install:
	@${INSTALL_DIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/tutorial/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${INSTALL_DIR} ${DOCSDIR}
	@${CP} -R ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/doc/* ${DOCSDIR}
	@${FIND} ${EXAMPLESDIR}/* -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
.for f in ${MAN1}
	${INSTALL_MAN} ${MANDIR}/${f} ${PREFIX}/man/man1
.endfor
.endif

.include <bsd.port.mk>
