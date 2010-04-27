# New ports collection makefile for:	py-soya3d
# Date created:				2005-10-04
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	soya3d
PORTVERSION=	0.14
PORTREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	http://download.gna.org/soya/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Soya-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Very high level 3D engine for Python

BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	cal3d.12:${PORTSDIR}/graphics/cal3d \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/editobj/editor.py:${PORTSDIR}/graphics/py-editobj \
		${PYTHON_SITELIBDIR}/tofu/client.py:${PORTSDIR}/net/py-tofu \
		${PYTHON_SITELIBDIR}/cerealizer/__init__.py:${PORTSDIR}/security/py-cerealizer

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_OPENAL=	al alut
USE_GL=		glew
USE_GMAKE=	yes
USE_SDL=	sdl

PYDISTUTILS_PKGNAME=	Soya

MANDIR=	${WRKDIR}/${DISTNAME}/manpage/man1
MAN1=	soya_editor.1
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
SOYATUTVER=	0.14

.if !defined(NOPORTEXAMPLES)
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
.if !defined(NOPORTEXAMPLES)
	@${INSTALL_DIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/tutorial/* ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR}/* -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endif

.if !defined(NOPORTDOCS)
	@${INSTALL_DIR} ${DOCSDIR}
.for FILE in AUTHORS README
	@${INSTALL_DATA} ${WRKDIR}/SoyaTutorial-${SOYATUTVER}/${FILE} ${DOCSDIR}
.endfor
.endif

.for FILE in ${MAN1}
	${INSTALL_MAN} ${MANDIR}/${FILE} ${PREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
