# New ports collection makefile for:    PIL
# Date created:         02 November 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imaging
PORTVERSION=	1.1.5
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/ \
	        http://www.pythonware.net/storage/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Imaging-${PORTVERSION}

MAINTAINER=	mainland@apeiron.net
COMMENT=	The Python Imaging Library

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

DIST_SUBDIR=	 python
USE_PYTHON=	 yes
USE_PYDISTUTILS=yes

DOCDIRS=		${PREFIX}/share/doc/py-imaging
EXAMPLESDIR=	${PREFIX}/share/examples/py-imaging

.include <bsd.port.pre.mk>

post-install:
.for file in ImPlatform.h Imaging.h
	${INSTALL_DATA} ${WRKSRC}/libImaging/${file} ${PYTHON_INCLUDEDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Scripts/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
