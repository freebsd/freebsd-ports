# New ports collection makefile for:	eric
# Date created:				20 January 2004
# Whom:					leafy <leafy@leafy.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	eric
PORTVERSION=	3.3.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.die-offenbachs.de/detlev/files/

MAINTAINER=	leafy@leafy.idv.tw
COMMENT=	A Python IDE implemented using PyQt and QScintilla

BUILD_DEPENDS=	${X11BASE}/lib/libqscintilla.so:${PORTSDIR}/x11-toolkits/qscintilla\
		${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip\
		pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_PYTHON=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes
# dirty hack to fix plist if PREFIX != PYTHONBASE
DESTDIR_LIBS=	${PYTHON_SITELIBDIR:S/${PYTHONBASE}/${PREFIX}/}

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} install.py -b ${PREFIX}/bin/ \
		-d ${DESTDIR_LIBS}

.include <bsd.port.mk>
