# New ports collection makefile for:	ivan
# Date created:		11 Nov 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	ivan
PORTVERSION=	0.50
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ivan

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A graphical roguelike game

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=/var/games

STATEDIR=	/var/games/ivan

post-patch:
	@${REINPLACE_CMD} -e 's|IvanSave|.IvanSave|g' ${WRKSRC}/Main/Source/game.cpp

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
