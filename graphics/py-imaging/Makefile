# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imaging
PORTVERSION=	1.1.7
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/media/downloads/ \
		http://www.pythonware.net/storage/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Imaging-${PORTVERSION}

MAINTAINER=	mainland@apeiron.net
COMMENT=	The Python Imaging Library

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		freetype.9:${PORTSDIR}/print/freetype2

UNIQUENAME=	py-${PORTNAME}

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PIL
PYDISTUTILS_EGGINFODIR=	${PYTHON_SITELIBDIR}/PIL

PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	TKINTER
TKINTER_DESC=	tkinter for X support

OPTIONS_DEFAULT=	TKINTER

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTKINTER}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
PLIST_SUB+=	TKINTER=""
.else
PLIST_SUB+=	TKINTER="@comment "
.endif

.if ! ${PORT_OPTIONS:MTKINTER}
post-patch:
	@${REINPLACE_CMD} -e 's|if _tkinter|if None|g' ${WRKSRC}/setup.py
.endif

post-install:
.for file in ImPlatform.h Imaging.h
	${INSTALL_DATA} ${WRKSRC}/libImaging/${file} ${PYTHON_INCLUDEDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Scripts/* ${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
