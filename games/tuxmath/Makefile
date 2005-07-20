# New ports collection makefile for:	tuxmath
# Date created:				14 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxmath
DISTVERSION=	2001.09.07-0102
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Educational arcade game starring Tux

USE_GMAKE=	yes
USE_SDL=	image mixer sdl
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
# Remove CVS and .xvpics directories
.for d in CVS .xvpics
	@${FIND} ${WRKSRC} -type d -name ${d} -print0 | \
		${XARGS} -0 ${RM} -rf
.endfor

post-install:
# Fix permissions
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644
	@${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/tuxmath|${DATADIR}| ; \
			s|\(BIN_PREFIX=\).*|\1${PREFIX}/bin/| ; \
			s|sdl-config|${SDL_CONFIG}|' \
				${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
