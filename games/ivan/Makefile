# New ports collection makefile for:	ivan
# Date created:		11 Nov 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	ivan
PORTVERSION=	0.50
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/IVAN/IVAN%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A graphical roguelike game

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--localstatedir=/var/games

STATEDIR=	/var/games/ivan

PORTSCOUT=	skipv:0.301,0.310,0.311,0.401,0.410,0.420,0.430

post-patch:
	@${REINPLACE_CMD} -e 's|IvanSave|.IvanSave|g' ${WRKSRC}/Main/Source/game.cpp
	@${REINPLACE_CMD} -Ee 's|(fearray<type>::~?fearray)<type>|\1|' \
		${WRKSRC}/FeLib/Include/fearray.h
	@${REINPLACE_CMD} -Ee 's|([a-z]+<[a-z ,]+>::~?[a-z]+)<[a-z ,]+>|\1|' \
		${WRKSRC}/Main/Source/script.cpp
	@${REINPLACE_CMD} -e 's|truth(|bool(|' ${WRKSRC}/Main/Source/fluid.cpp \
		${WRKSRC}/Main/Include/char.h ${WRKSRC}/Main/Include/lsquare.h \
		${WRKSRC}/FeLib/Include/save.h ${WRKSRC}/Main/Include/lsquare.h \
		${WRKSRC}/Main/Include/human.h ${WRKSRC}/Main/Source/command.cpp \
		${WRKSRC}/Main/Include/stack.h ${WRKSRC}/Main/Source/lsquare.cpp \
		${WRKSRC}/Main/Source/lterras.cpp

post-install:
	${CHGRP} games ${PREFIX}/bin/ivan
	${CHMOD} g+s ${PREFIX}/bin/ivan
.if !exists(${STATEDIR})
	${MKDIR} ${STATEDIR}
	${TOUCH} ${STATEDIR}/ivan-highscore.scores
	${MKDIR} ${STATEDIR}/Bones
	${CHGRP} -R games ${STATEDIR}
	${CHMOD} -R g+w ${STATEDIR}
.endif

.include <bsd.port.mk>
