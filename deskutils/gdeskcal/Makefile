# New ports collection makefile for:	gdeskcal
# Date created:		27 February 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gdeskcal
PORTVERSION=	0.50
CATEGORIES=	deskutils python gnome
MASTER_SITES=	http://www.pycage.de/download/
DISTNAME=	gDeskCal-${PORTVERSION:S/./_/}

MAINTAINER=	martin.klaffenboeck@gmx.at
COMMENT=	A calendar for the gnome2 desktop with smooth alpha-blending

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

WRKSRC=		${WRKDIR}/gDeskCal-${PORTVERSION}

USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehier
NO_BUILD=	yes

DATA_DIRS=	code data skins

do-install:
	${MKDIR} ${PREFIX}/share/gnome/gdeskcal
	for d in ${DATA_DIRS}; do \
	    ${MKDIR} ${PREFIX}/share/gnome/gdeskcal/$$d ; \
	    cd ${WRKSRC}/$$d && ${FIND} . | \
	    	cpio -pdm -L -R ${LIBOWN}:${LIBGRP}  \
		${PREFIX}/share/gnome/gdeskcal/$$d ; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/gdeskcal \
		${PREFIX}/share/gnome/gdeskcal

	${MKDIR} ${PREFIX}/share/locale/ar/LC_MESSAGES

.for i in ar cs de el es fr he hu it ja nl ru tr zh_CN
	${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/${i}/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/${i}/LC_MESSAGES
.endfor
	${LN} -sf ${PREFIX}/share/gnome/gdeskcal/gdeskcal ${PREFIX}/bin/gdeskcal

.include <bsd.port.mk>
