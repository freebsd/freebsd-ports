# New ports collection makefile for:	4stAttack
# Date created:			26 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	4stattack
PORTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	forcedattack
DISTNAME=	4stAttack-${PORTVERSION}

MAINTAINER=	jylefort@brutele.be
COMMENT=	Connect four stones in a straight line

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

PYC=		PYTHON="${PYTHON_CMD}" ${SH} ${SCRIPTDIR}/py-compile

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|; s|%%PYTHON%%|${PYTHON_CMD}|' \
		${WRKSRC}/4stattack

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/4stattack \
		${PREFIX}/bin

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} \
		${WRKSRC}/4stattack.py \
		${WRKSRC}/animator.py \
		${WRKSRC}/board.py \
		${WRKSRC}/chat.py \
		${WRKSRC}/creditsscreen.py \
		${WRKSRC}/endgamedialog.py \
		${WRKSRC}/endscreen.py \
		${WRKSRC}/game.py \
		${WRKSRC}/gamelog.py \
		${WRKSRC}/gamescreen.py \
		${WRKSRC}/inisettings.py \
		${WRKSRC}/multiplayerscreen.py \
		${WRKSRC}/quit.py \
		${WRKSRC}/rules.py \
		${WRKSRC}/scoremap.py \
		${WRKSRC}/setini.py \
		${WRKSRC}/settings.ini \
		${WRKSRC}/settingsscreen.py \
		${WRKSRC}/startscreen.py \
		${WRKSRC}/technical.ttf \
		${WRKSRC}/testgui.py \
		${WRKSRC}/testini.py \
		${WRKSRC}/themeresizer.py \
		${WRKSRC}/themeresizer.sh \
		${WRKSRC}/version \
		${DATADIR}
	${PYC} --basedir ${DATADIR} \
		${DATADIR}/4stattack.py \
		${DATADIR}/animator.py \
		${DATADIR}/board.py \
		${DATADIR}/chat.py \
		${DATADIR}/creditsscreen.py \
		${DATADIR}/endgamedialog.py \
		${DATADIR}/endscreen.py \
		${DATADIR}/game.py \
		${DATADIR}/gamelog.py \
		${DATADIR}/gamescreen.py \
		${DATADIR}/inisettings.py \
		${DATADIR}/multiplayerscreen.py \
		${DATADIR}/quit.py \
		${DATADIR}/rules.py \
		${DATADIR}/scoremap.py \
		${DATADIR}/setini.py \
		${DATADIR}/settingsscreen.py \
		${DATADIR}/startscreen.py \
		${DATADIR}/testgui.py \
		${DATADIR}/testini.py \
		${DATADIR}/themeresizer.py

	${MKDIR} ${DATADIR}/data/music
	${INSTALL_DATA} \
		${WRKSRC}/data/music/4stattack.ogg \
		${DATADIR}/data/music

	${MKDIR} ${DATADIR}/data/themes/clean
	${INSTALL_DATA} \
		${WRKSRC}/data/themes/clean/audio.ini \
		${WRKSRC}/data/themes/clean/graphics.ini \
		${DATADIR}/data/themes/clean

	${MKDIR} ${DATADIR}/data/themes/clean/1024x768
	${INSTALL_DATA} \
		${WRKSRC}/data/themes/clean/1024x768/awaitingconnection.png \
		${WRKSRC}/data/themes/clean/1024x768/back.png \
		${WRKSRC}/data/themes/clean/1024x768/background.png \
		${WRKSRC}/data/themes/clean/1024x768/chakie.png \
		${WRKSRC}/data/themes/clean/1024x768/connecting-plain.png \
		${WRKSRC}/data/themes/clean/1024x768/connecting.png \
		${WRKSRC}/data/themes/clean/1024x768/credits.png \
		${WRKSRC}/data/themes/clean/1024x768/cursor.png \
		${WRKSRC}/data/themes/clean/1024x768/draw.png \
		${WRKSRC}/data/themes/clean/1024x768/error-connecting.png \
		${WRKSRC}/data/themes/clean/1024x768/frame.png \
		${WRKSRC}/data/themes/clean/1024x768/frm_bl.png \
		${WRKSRC}/data/themes/clean/1024x768/frm_br.png \
		${WRKSRC}/data/themes/clean/1024x768/frm_left.png \
		${WRKSRC}/data/themes/clean/1024x768/frm_right.png \
		${WRKSRC}/data/themes/clean/1024x768/frm_tl.png \
		${WRKSRC}/data/themes/clean/1024x768/frm_top.png \
		${WRKSRC}/data/themes/clean/1024x768/frm_tr.png \
		${WRKSRC}/data/themes/clean/1024x768/fullscreen.png \
		${WRKSRC}/data/themes/clean/1024x768/graphics.png \
		${WRKSRC}/data/themes/clean/1024x768/green-zebra.png \
		${WRKSRC}/data/themes/clean/1024x768/grid.png \
		${WRKSRC}/data/themes/clean/1024x768/hostagame.png \
		${WRKSRC}/data/themes/clean/1024x768/joinagame.png \
		${WRKSRC}/data/themes/clean/1024x768/keepplaying.png \
		${WRKSRC}/data/themes/clean/1024x768/korruptor.png \
		${WRKSRC}/data/themes/clean/1024x768/locations.ini \
		${WRKSRC}/data/themes/clean/1024x768/logo.png \
		${WRKSRC}/data/themes/clean/1024x768/multiplayer.png \
		${WRKSRC}/data/themes/clean/1024x768/music.png \
		${WRKSRC}/data/themes/clean/1024x768/ok.png \
		${WRKSRC}/data/themes/clean/1024x768/playervscpu.png \
		${WRKSRC}/data/themes/clean/1024x768/programming.png \
		${WRKSRC}/data/themes/clean/1024x768/pygame.png \
		${WRKSRC}/data/themes/clean/1024x768/quit.png \
		${WRKSRC}/data/themes/clean/1024x768/quitgame.png \
		${WRKSRC}/data/themes/clean/1024x768/radio-off.png \
		${WRKSRC}/data/themes/clean/1024x768/radio-on.png \
		${WRKSRC}/data/themes/clean/1024x768/radio.png \
		${WRKSRC}/data/themes/clean/1024x768/selector.png \
		${WRKSRC}/data/themes/clean/1024x768/selector1.png \
		${WRKSRC}/data/themes/clean/1024x768/selector2.png \
		${WRKSRC}/data/themes/clean/1024x768/settings.png \
		${WRKSRC}/data/themes/clean/1024x768/slm-text.png \
		${WRKSRC}/data/themes/clean/1024x768/slm.png \
		${WRKSRC}/data/themes/clean/1024x768/start.png \
		${WRKSRC}/data/themes/clean/1024x768/stone_1.png \
		${WRKSRC}/data/themes/clean/1024x768/stone_2.png \
		${WRKSRC}/data/themes/clean/1024x768/thanks.png \
		${WRKSRC}/data/themes/clean/1024x768/wannaquit.png \
		${WRKSRC}/data/themes/clean/1024x768/won_1.png \
		${WRKSRC}/data/themes/clean/1024x768/won_2.png \
		${DATADIR}/data/themes/clean/1024x768

	${MKDIR} ${DATADIR}/gui
	${INSTALL_DATA} \
		${WRKSRC}/gui/__init__.py \
		${WRKSRC}/gui/button.py \
		${WRKSRC}/gui/canvas.py \
		${WRKSRC}/gui/checkbox.py \
		${WRKSRC}/gui/dialog.py \
		${WRKSRC}/gui/editfield.py \
		${WRKSRC}/gui/fader.py \
		${WRKSRC}/gui/image.py \
		${WRKSRC}/gui/label.py \
		${WRKSRC}/gui/messagebox.py \
		${WRKSRC}/gui/progress.py \
		${WRKSRC}/gui/widget.py \
		${WRKSRC}/gui/widget_manager.py \
		${DATADIR}/gui
	${PYC} --basedir ${DATADIR}/gui \
		${DATADIR}/gui/__init__.py \
		${DATADIR}/gui/button.py \
		${DATADIR}/gui/canvas.py \
		${DATADIR}/gui/checkbox.py \
		${DATADIR}/gui/dialog.py \
		${DATADIR}/gui/editfield.py \
		${DATADIR}/gui/fader.py \
		${DATADIR}/gui/image.py \
		${DATADIR}/gui/label.py \
		${DATADIR}/gui/messagebox.py \
		${DATADIR}/gui/progress.py \
		${DATADIR}/gui/widget.py \
		${DATADIR}/gui/widget_manager.py

	${MKDIR} ${DATADIR}/gui/dialogs
	${INSTALL_DATA} \
		${WRKSRC}/gui/dialogs/dialog \
		${WRKSRC}/gui/dialogs/end_game.py \
		${WRKSRC}/gui/dialogs/info_map.py \
		${WRKSRC}/gui/dialogs/info_scenario.py \
		${WRKSRC}/gui/dialogs/info_units.py \
		${WRKSRC}/gui/dialogs/main_dialog.py \
		${WRKSRC}/gui/dialogs/new_game.py \
		${WRKSRC}/gui/dialogs/select_scenario.py \
		${WRKSRC}/gui/dialogs/setup_client.py \
		${WRKSRC}/gui/dialogs/setup_network.py \
		${WRKSRC}/gui/dialogs/setup_players.py \
		${WRKSRC}/gui/dialogs/start_game.py \
		${WRKSRC}/gui/dialogs/wait_client.py \
		${DATADIR}/gui/dialogs
	${PYC} --basedir ${DATADIR}/gui/dialogs \
		${DATADIR}/gui/dialogs/end_game.py \
		${DATADIR}/gui/dialogs/info_map.py \
		${DATADIR}/gui/dialogs/info_scenario.py \
		${DATADIR}/gui/dialogs/info_units.py \
		${DATADIR}/gui/dialogs/main_dialog.py \
		${DATADIR}/gui/dialogs/new_game.py \
		${DATADIR}/gui/dialogs/select_scenario.py \
		${DATADIR}/gui/dialogs/setup_client.py \
		${DATADIR}/gui/dialogs/setup_network.py \
		${DATADIR}/gui/dialogs/setup_players.py \
		${DATADIR}/gui/dialogs/start_game.py \
		${DATADIR}/gui/dialogs/wait_client.py

	${MKDIR} ${DATADIR}/players
	${INSTALL_DATA} \
		${WRKSRC}/players/__init__.py \
		${WRKSRC}/players/agressive.py \
		${WRKSRC}/players/connectscore.py \
		${WRKSRC}/players/human.py \
		${WRKSRC}/players/minmax.py \
		${WRKSRC}/players/multiplayer.py \
		${WRKSRC}/players/multiplayer_receiver.py \
		${WRKSRC}/players/multiplayer_sender.py \
		${WRKSRC}/players/neuralai.py \
		${WRKSRC}/players/player.py \
		${WRKSRC}/players/randomai.py \
		${WRKSRC}/players/strategic.py \
		${WRKSRC}/players/treeai.py \
		${WRKSRC}/players/weighted.py \
		${DATADIR}/players
	${PYC} --basedir ${DATADIR}/players \
		${DATADIR}/players/__init__.py \
		${DATADIR}/players/agressive.py \
		${DATADIR}/players/connectscore.py \
		${DATADIR}/players/human.py \
		${DATADIR}/players/minmax.py \
		${DATADIR}/players/multiplayer.py \
		${DATADIR}/players/multiplayer_receiver.py \
		${DATADIR}/players/multiplayer_sender.py \
		${DATADIR}/players/neuralai.py \
		${DATADIR}/players/player.py \
		${DATADIR}/players/randomai.py \
		${DATADIR}/players/strategic.py \
		${DATADIR}/players/treeai.py \
		${DATADIR}/players/weighted.py

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/changelog.txt \
		${WRKSRC}/credits.txt \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
