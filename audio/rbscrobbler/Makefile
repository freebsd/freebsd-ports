# New ports collection Makefile for:	rbscrobbler
# Date created:				2005-01-30
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	rbscrobbler
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	http://members.cox.net/alexrevo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rhythmbox plugin for Audioscrobbler

BUILD_DEPENDS=	rhythmbox:${PORTSDIR}/audio/rhythmbox \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2
RUN_DEPENDS=	rhythmbox:${PORTSDIR}/audio/rhythmbox \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_PYTHON=	yes
USE_REINPLACE=	yes
CFLAGS+=	"-I${PYTHON_INCLUDEDIR}"

post-patch:
	${REINPLACE_CMD} -e "s,CFLAGS =,CFLAGS+= -I${PYTHON_INCLUDEDIR}," \
		${WRKSRC}/trayicon/Makefile

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}; ${INSTALL_DATA} Audioscrobbler.py Debug.py MyQueue.py \
		Rhythmbox_Bonobo.py RLInput.py singletonmixin.py ${DATADIR}
	cd ${WRKSRC}; ${INSTALL_SCRIPT} rbscrobbler.py ${DATADIR}
	ln -sf ${DATADIR}/rbscrobbler.py ${PREFIX}/bin/rbscrobbler
	${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${DATADIR}/images
	${MKDIR} ${DATADIR}/trayicon
	cd ${WRKSRC}; ${INSTALL_DATA} trayicon/__init__.py \
		trayicon/trayicon.so ${DATADIR}/trayicon

.include <bsd.port.mk>
