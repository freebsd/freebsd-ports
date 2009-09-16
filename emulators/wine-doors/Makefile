# New ports collection makefile for:	wine-doors
# Date created:		7 July 2007
# Whom:			ports@mcdermottroe.com
#
# $FreeBSD$
#

PORTNAME=	wine-doors
PORTVERSION=	0.1.2
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.wine-doors.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Windows application management for the GNOME Desktop

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/${PYLXML_EGG}:${PORTSDIR}/devel/py-lxml \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtksourceview.so:${PORTSDIR}/x11-toolkits/py-gnome-desktop \
		bash:${PORTSDIR}/shells/bash \
		cabextract:${PORTSDIR}/archivers/cabextract \
		orange:${PORTSDIR}/archivers/liborange \
		unzip:${PORTSDIR}/archivers/unzip \
		wine:${PORTSDIR}/emulators/wine

USE_PYTHON=	2.4+

NO_BUILD=	yes

SUB_FILES=	preferences.xml

post-patch:
	@${REINPLACE_CMD} 's|/etc/${PORTNAME}|${PREFIX}/etc/${PORTNAME}|g' \
		${WRKSRC}/src/preferences.py
	@${GREP} -lr '^#!/bin/bash' ${WRKDIR} | ${XARGS} \
		${REINPLACE_CMD} 's|^#!/bin/bash|#!${LOCALBASE}/bin/bash|'

do-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/preferences.xml ${PREFIX}/etc/${PORTNAME}
	${PYTHON_CMD} ${WRKSRC}/setup.py install --prefix=${PREFIX}

.include <bsd.port.pre.mk>

PYLXML_EGG!=	${MAKE} -f ${PORTSDIR}/devel/py-lxml/Makefile -V PYLXML_EGG

.include <bsd.port.post.mk>
