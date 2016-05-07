# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imaging
PORTVERSION=	1.1.7
PORTREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/media/downloads/ \
		http://www.pythonware.net/storage/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Imaging-${PORTVERSION}

MAINTAINER=	mainland@apeiron.net
COMMENT=	The Python Imaging Library

LIB_DEPENDS=	liblcms.so:graphics/lcms \
		libfreetype.so:print/freetype2

DEPRECATED=	Unmaintained upstream; use graphics/py-pillow
EXPIRATION_DATE=2016-03-11

USES=		jpeg python
DIST_SUBDIR=	python
USE_PYTHON=	distutils autoplist concurrent

PLIST_FILES=	%%PYTHON_INCLUDEDIR%%/ImPlatform.h %%PYTHON_INCLUDEDIR%%/Imaging.h
PORTDOCS=	*
PORTEXAMPLES=	*

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pillow-*

OPTIONS_DEFINE=	DOCS TKINTER
TKINTER_DESC=	tkinter for X support

OPTIONS_DEFAULT=	TKINTER

TKINTER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter
TKINTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MTKINTER}
post-patch:
	@${REINPLACE_CMD} -e 's|if _tkinter|if None|g' ${WRKSRC}/setup.py
.endif

post-install:
.for file in ImPlatform.h Imaging.h
	@${MKDIR} ${STAGEDIR}${PYTHON_INCLUDEDIR}
	${INSTALL_DATA} ${WRKSRC}/libImaging/${file} ${STAGEDIR}${PYTHON_INCLUDEDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Scripts/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
