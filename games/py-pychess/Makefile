# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pychess
DISTVERSION=	0.10rc1
PORTREVISION=	2
#PORTEPOCH=	0
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A GTK chess client written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=3-2.5.1_1:${PORTSDIR}/databases/py-sqlite3

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	PYGSTREAMER CRAFTY GNUCHESS PHALANX SJENG STOCKFISH
PYGSTREAMER_DESC=	Install gst-python for audio support
CRAFTY_DESC=	Install crafty (chess engine)
GNUCHESS_DESC=	Install gnuchess (chess engine)
PHALANX_DESC=	Install phalanx (chess engine)
SJENG_DESC=	Install sjeng (chess engine)
STOCKFISH_DESC=	Install stockfish (chess engine)

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

PYDISTUTILS_PKGVERSION=	${DISTVERSION}

USE_GNOME=	pygnomedesktop
USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

REINPLACE_ARGS=	-i.bak -e 's,%%PREFIX%%,${PREFIX},' -e 's,share/games/pychess,${DATADIR},' -e '1s,/usr/bin/python,/usr/bin/env python${PYTHON_VER},'

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
MANCOMPRESSED=	yes
.else
MAKE_ENV+=	NO_INSTALL_MANPAGES=${NO_INSTALL_MANPAGES}
.endif

NO_STAGE=	yes
post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} ${PORTNAME} ${PYSETUP} lib/pychess/widgets/newGameDialog.py lib/pychess/Players/PyChess.py

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYGSTREAMER}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gstreamer>=0.10.8:${PORTSDIR}/multimedia/py-gstreamer
.endif

.if ${PORT_OPTIONS:MCRAFTY}
RUN_DEPENDS+=	crafty:${PORTSDIR}/games/crafty
.endif

.if ${PORT_OPTIONS:MGNUCHESS}
RUN_DEPENDS+=	gnuchess:${PORTSDIR}/games/gnuchess
.endif

.if ${PORT_OPTIONS:MPHALANX}
RUN_DEPENDS+=	phalanx:${PORTSDIR}/games/phalanx
.endif

.if ${PORT_OPTIONS:MSJENG}
RUN_DEPENDS+=	sjeng:${PORTSDIR}/games/sjeng
.endif

.if ${PORT_OPTIONS:MSTOCKFISH}
RUN_DEPENDS+=	stockfish:${PORTSDIR}/games/stockfish
.endif

.include <bsd.port.mk>
