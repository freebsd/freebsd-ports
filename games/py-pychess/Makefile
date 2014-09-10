# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pychess
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://www.pychess.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK chess client written in Python

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=3-2.5.1_1:${PORTSDIR}/databases/py-sqlite3

USES=		desktop-file-utils gettext
USE_GNOME=	pygnomedesktop
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		PYGSTREAMER
OPTIONS_GROUP=		ENGINES
OPTIONS_GROUP_ENGINES=	CRAFTY GNUCHESS PHALANX SJENG STOCKFISH

CRAFTY_DESC=		Use crafty
CRAFTY_RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty
ENGINES_DESC=		Chess Engines
GNUCHESS_DESC=		Use gnuchess
GNUCHESS_RUN_DEPENDS=	gnuchess:${PORTSDIR}/games/gnuchess
PHALANX_DESC=		Use phalanx
PHALANX_RUN_DEPENDS=	phalanx:${PORTSDIR}/games/phalanx
SJENG_DESC=		Use sjeng
SJENG_RUN_DEPENDS+=	sjeng:${PORTSDIR}/games/sjeng
STOCKFISH_DESC=		Use stockfish
STOCKFISH_RUN_DEPENDS=	stockfish:${PORTSDIR}/games/stockfish
PYGSTREAMER_DESC=	Install gst-python for audio support
PYGSTREAMER_USE=	gstreamer=python

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e \
		's|gtk.gdk.threads_init()|gobject.threads_init()|' \
		${WRKSRC}/lib/pychess/Main.py
	@${REINPLACE_CMD} -e \
		'/^#!/d' ${WRKSRC}/lib/pychess/Players/PyChess.py
	@${REINPLACE_CMD} -e \
		's|"games"|""| ; \
		 s|"share/games"|""| ; \
		 s|"local/share"|""| ; \
		 s|"local/games"|""| ; \
		 s|"local/share/games"|""|' \
		${WRKSRC}/lib/pychess/System/prefix.py
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/lib/pychess/widgets/newGameDialog.py
	@${REINPLACE_CMD} -e \
		's|"/usr/share/sounds",|| ; \
		 s|/usr/local/share|${LOCALBASE}/share|' \
		${WRKSRC}/lib/pychess/widgets/preferencesDialog.py

.include <bsd.port.mk>
