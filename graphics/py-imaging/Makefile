# New ports collection makefile for:    PIL
# Date created:         02 November 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imaging
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/ \
	        http://www.pythonware.net/storage/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Imaging-${PORTVERSION}

MAINTAINER=	mainland@apeiron.net
COMMENT=	The Python Imaging Library

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

LATEST_LINK=	py-${PORTNAME}

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PORTDOCS=	*

DOCDIRS=	${PREFIX}/share/doc/py-imaging
EXAMPLESDIR=	${PREFIX}/share/examples/py-imaging

OPTIONS=	TKINTER "Build with tkinter for X support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TKINTER)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
PLIST_SUB+=	TKINTER=""
.else
PLIST_SUB+=	TKINTER="@comment "
.endif

post-install:
.for file in ImPlatform.h Imaging.h
	${INSTALL_DATA} ${WRKSRC}/libImaging/${file} ${PYTHON_INCLUDEDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Scripts/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
