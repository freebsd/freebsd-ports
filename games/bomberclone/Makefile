# New ports collection makefile for:	bomberclone
# Date created:				5 May 2003
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	bomberclone
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Reimplementation of Atomic Bomber Man

USE_SDL=	image mixer sdl
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
CONFIGURE_ARGS=	--target=""
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

.include <bsd.port.mk>
