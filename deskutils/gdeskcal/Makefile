# New ports collection makefile for:	gdeskcal
# Date created:		27 February 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gdeskcal
PORTVERSION=	0.30
CATEGORIES=	deskutils python gnome
MASTER_SITES=	http://www.pycage.de/download/
DISTNAME=	gDeskCal-${PORTVERSION:S/./_/}

MAINTAINER=	martin.klaffenboeck@gmx.at
COMMENT=	A calendar for the gnome2 desktop with smooth alpha-blending

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

WRKSRC=		${WRKDIR}/gDeskCal-${PORTVERSION}

USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
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
# XXX Gack! This is ugly, but somewhat necessary.
	${INSTALL_DATA} ${WRKSRC}/locale/ar_AE/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/ar/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/cs/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/cs/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/de/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/de/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/el/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/el/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/es/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/es/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/fr/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/fr/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/he/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/he/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/hu/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/hu/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/it/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/it/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/ja/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/ja/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/nl/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/nl/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/ru/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/ru/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/tr/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/tr/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/zh_CN/LC_MESSAGES/gdeskcal.mo \
		${PREFIX}/share/locale/zh_CN/LC_MESSAGES
	${LN} -sf ${PREFIX}/share/gnome/gdeskcal/gdeskcal ${PREFIX}/bin/gdeskcal

.include <bsd.port.mk>
