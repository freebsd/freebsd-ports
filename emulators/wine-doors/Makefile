# Created by: ports@mcdermottroe.com
# $FreeBSD$

PORTNAME=	wine-doors
PORTVERSION=	0.1.2
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	http://www.wine-doors.org/releases/

MAINTAINER=	eg@fbsd.lt
COMMENT=	Windows application management for the GNOME Desktop

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtksourceview.so:${PORTSDIR}/x11-toolkits/py-gnome-desktop \
		bash:${PORTSDIR}/shells/bash \
		cabextract:${PORTSDIR}/archivers/cabextract \
		orange:${PORTSDIR}/archivers/liborange \
		unzip:${PORTSDIR}/archivers/unzip \
		wine:${PORTSDIR}/emulators/wine

USE_PYTHON=	yes

NO_BUILD=	yes

SUB_FILES=	preferences.xml

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|/etc/${PORTNAME}|${PREFIX}/etc/${PORTNAME}|g' \
		${WRKSRC}/src/preferences.py
	@${GREP} -lr '^#!/bin/bash' ${WRKDIR} | ${XARGS} \
		${REINPLACE_CMD} 's|^#!/bin/bash|#!${LOCALBASE}/bin/bash|'

do-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/preferences.xml ${PREFIX}/etc/${PORTNAME}
	${PYTHON_CMD} ${WRKSRC}/setup.py install --prefix=${PREFIX}

.include <bsd.port.mk>
