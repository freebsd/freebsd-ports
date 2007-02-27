# New ports collection makefile for:	warp-rogue
# Date created:		2007-02-26
# Whom:			Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	wrogue
PORTVERSION=	0.7.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	todoom

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	A gothic science fantasy roguelike game

USE_BZIP2=	yes
USE_SDL=	yes
USE_GMAKE=	yes
MAKEFILE=	unix.mak
ALL_TARGET=	release
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKDIR}

SUB_FILES=	unix.mak
SUB_LIST=	WRKSRC=${WRKSRC}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|-march=i586||; \
		s|gcc|${CC}|; \
		s|CFLAGS=|CFLAGS+=|" \
	${WRKSRC}/src/unix.mak

	@${REINPLACE_CMD} -e "s|\./data/|${DATADIR}/|" \
		${WRKSRC}/src/unix/be_unix.c

.include <bsd.port.post.mk>
