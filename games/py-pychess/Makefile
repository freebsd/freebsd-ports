# New ports collection makefile for:	pychess
# Date created:		2008-01-23
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pychess
DISTVERSION=	0.8beta4
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	games
MASTER_SITES=	http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A GTK chess client written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=3-2.5.1_1:${PORTSDIR}/databases/py-sqlite3

INSTALLS_ICONS=	yes

OPTIONS=	PYGSTREAMER "Install gst-python for audio support" off \
		CRAFTY "Install crafty (chess engine)" off \
		GNUCHESS "Install gnuchess (chess engine)" off \
		PHALANX "Install phalanx (chess engine)" off \
		SJENG "Install sjeng (chess engine)" off
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

PYDISTUTILS_PKGVERSION=	${DISTVERSION}

USE_GNOME=	pygnomedesktop
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

REINPLACE_ARGS=	-i.bak -e 's,%%PREFIX%%,${PREFIX},' -e 's,share/games/pychess,${DATADIR},'

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
MANCOMPRESSED=	yes
.endif

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} ${PORTNAME} ${PYSETUP}

.include <bsd.port.pre.mk>

.if defined (WITH_PYGSTREAMER)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}-gstreamer>=0.10.8:${PORTSDIR}/py-gstreamer
.endif

.if defined (WITH_CRAFTY)
RUN_DEPENDS+=	crafty:${PORTSDIR}/games/crafty
.endif

.if defined (WITH_GNUCHESS)
RUN_DEPENDS+=	gnuchess:${PORTSDIR}/games/gnuchess
.endif

.if defined (WITH_PHALANX)
RUN_DEPENDS+=	phalanx:${PORTSDIR}/games/phalanx
.endif

.if defined (WITH_SJENG)
RUN_DEPENDS+=	sjeng:${PORTSDIR}/games/sjeng
.endif

.include <bsd.port.post.mk>
