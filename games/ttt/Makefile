# New ports collection makefile for:	ttt
# Date created:				11 July 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	ttt
PORTVERSION=	2011.04
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/ttt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple one or two player Tic Tac Toe game

# net/ttt
CONFLICTS=	ttt-1*
NO_LATEST_LINK=	yes

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_SDL=	sdl
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal automake autoheader autoconf
AUTOMAKE_ARGS=	--add-missing --force
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/SDL_mixer/d' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's|\./images|${DATADIR}/images|g' ${WRKSRC}/src/init.c

post-install:
	@${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/*.bmp ${DATADIR}/images

.include <bsd.port.mk>
