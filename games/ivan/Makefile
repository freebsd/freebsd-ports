# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	ivan
PORTVERSION=	0.50
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/IVAN/IVAN%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical roguelike game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: use of overloaded operator '<<' is ambiguous
BROKEN_armv7=		fails to compile: use of overloaded operator '<<' is ambiguous

USES=		gmake sdl
USE_SDL=	sdl
USE_CXXSTD=	c++98
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--localstatedir=/var/games

PORTSCOUT=	skipv:0.301,0.310,0.311,0.401,0.410,0.420,0.430

PORTDATA=	*

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
	${MKDIR} ${STAGEDIR}/var/games/ivan/Bones
	${TOUCH} ${STAGEDIR}/var/games/ivan/ivan-highscore.scores.sample

.include <bsd.port.mk>
