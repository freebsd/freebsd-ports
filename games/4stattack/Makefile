# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	4stattack
PORTVERSION=	2.1.4
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/forcedattack/4stAttack/${PORTVERSION}
DISTNAME=	4stAttack-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connect four stones in a straight line

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PYC=		PYTHON="${PYTHON_CMD}" ${SH} ${SCRIPTDIR}/py-compile

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|; s|%%PYTHON%%|${PYTHON_CMD}|' \
		${WRKSRC}/4stattack

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/4stattack \
		${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DATADIR}
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
		${STAGEDIR}${DATADIR}
	${PYC} --basedir ${DATADIR} \
		${STAGEDIR}${DATADIR}/4stattack.py \
		${STAGEDIR}${DATADIR}/animator.py \
		${STAGEDIR}${DATADIR}/board.py \
		${STAGEDIR}${DATADIR}/chat.py \
		${STAGEDIR}${DATADIR}/creditsscreen.py \
		${STAGEDIR}${DATADIR}/endgamedialog.py \
		${STAGEDIR}${DATADIR}/endscreen.py \
		${STAGEDIR}${DATADIR}/game.py \
		${STAGEDIR}${DATADIR}/gamelog.py \
		${STAGEDIR}${DATADIR}/gamescreen.py \
		${STAGEDIR}${DATADIR}/inisettings.py \
		${STAGEDIR}${DATADIR}/multiplayerscreen.py \
		${STAGEDIR}${DATADIR}/quit.py \
		${STAGEDIR}${DATADIR}/rules.py \
		${STAGEDIR}${DATADIR}/scoremap.py \
		${STAGEDIR}${DATADIR}/setini.py \
		${STAGEDIR}${DATADIR}/settingsscreen.py \
		${STAGEDIR}${DATADIR}/startscreen.py \
		${STAGEDIR}${DATADIR}/testgui.py \
		${STAGEDIR}${DATADIR}/testini.py \
		${STAGEDIR}${DATADIR}/themeresizer.py

	@${MKDIR} ${STAGEDIR}${DATADIR}/data/music
	${INSTALL_DATA} \
		${WRKSRC}/data/music/4stattack.ogg \
		${STAGEDIR}${DATADIR}/data/music

	@${MKDIR} ${STAGEDIR}${DATADIR}/data/themes/clean
	${INSTALL_DATA} \
		${WRKSRC}/data/themes/clean/audio.ini \
		${WRKSRC}/data/themes/clean/graphics.ini \
		${STAGEDIR}${DATADIR}/data/themes/clean

	@${MKDIR} ${STAGEDIR}${DATADIR}/data/themes/clean/1024x768
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
		${STAGEDIR}${DATADIR}/data/themes/clean/1024x768

	@${MKDIR} ${STAGEDIR}${DATADIR}/gui
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
		${STAGEDIR}${DATADIR}/gui
	${PYC} --basedir ${DATADIR}/gui \
		${STAGEDIR}${DATADIR}/gui/__init__.py \
		${STAGEDIR}${DATADIR}/gui/button.py \
		${STAGEDIR}${DATADIR}/gui/canvas.py \
		${STAGEDIR}${DATADIR}/gui/checkbox.py \
		${STAGEDIR}${DATADIR}/gui/dialog.py \
		${STAGEDIR}${DATADIR}/gui/editfield.py \
		${STAGEDIR}${DATADIR}/gui/fader.py \
		${STAGEDIR}${DATADIR}/gui/image.py \
		${STAGEDIR}${DATADIR}/gui/label.py \
		${STAGEDIR}${DATADIR}/gui/messagebox.py \
		${STAGEDIR}${DATADIR}/gui/progress.py \
		${STAGEDIR}${DATADIR}/gui/widget.py \
		${STAGEDIR}${DATADIR}/gui/widget_manager.py

	@${MKDIR} ${STAGEDIR}${DATADIR}/gui/dialogs
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
		${STAGEDIR}${DATADIR}/gui/dialogs
	${PYC} --basedir ${DATADIR}/gui/dialogs \
		${STAGEDIR}${DATADIR}/gui/dialogs/end_game.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/info_map.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/info_scenario.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/info_units.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/main_dialog.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/new_game.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/select_scenario.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/setup_client.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/setup_network.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/setup_players.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/start_game.py \
		${STAGEDIR}${DATADIR}/gui/dialogs/wait_client.py

	@${MKDIR} ${STAGEDIR}${DATADIR}/players
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
		${STAGEDIR}${DATADIR}/players
	${PYC} --basedir ${DATADIR}/players \
		${STAGEDIR}${DATADIR}/players/__init__.py \
		${STAGEDIR}${DATADIR}/players/agressive.py \
		${STAGEDIR}${DATADIR}/players/connectscore.py \
		${STAGEDIR}${DATADIR}/players/human.py \
		${STAGEDIR}${DATADIR}/players/minmax.py \
		${STAGEDIR}${DATADIR}/players/multiplayer.py \
		${STAGEDIR}${DATADIR}/players/multiplayer_receiver.py \
		${STAGEDIR}${DATADIR}/players/multiplayer_sender.py \
		${STAGEDIR}${DATADIR}/players/neuralai.py \
		${STAGEDIR}${DATADIR}/players/player.py \
		${STAGEDIR}${DATADIR}/players/randomai.py \
		${STAGEDIR}${DATADIR}/players/strategic.py \
		${STAGEDIR}${DATADIR}/players/treeai.py \
		${STAGEDIR}${DATADIR}/players/weighted.py

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/changelog.txt \
		${WRKSRC}/credits.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
