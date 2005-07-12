# New ports collection makefile for:	ttt
# Date created:				11 July 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	ttt
PORTVERSION=	2003.03.14
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/ttt/

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Simple one or two player Tic Tac Toe game

USE_GMAKE=	yes
USE_SDL=	mixer sdl
USE_REINPLACE=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

# net/ttt
CONFLICTS=	ttt-1*
NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}| ; \
			s|\(-Wall\)|${CFLAGS} \1|' \
				${WRKSRC}/${MAKEFILE}

# Enable/disable compilation optimizations
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/${MAKEFILE}
.endif

# Fix paths to ${DATADIR}
	@${REINPLACE_CMD} -e 's|\(images/\)|${DATADIR}/\1| ; \
			s|\(sounds/\)|${DATADIR}/\1|' \
				${WRKSRC}/ttt.c

do-install:
# Program
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
.for d in images sounds
	${CP} -R ${WRKSRC}/${d} ${DATADIR}
.endfor

# Fix wrong permissions
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.post.mk>
