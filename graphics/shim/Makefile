# New ports collection makefile for:	shim
# Date created:		24 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shim
DISTVERSION=	1.1b
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://corp.efnet.net/~lamer/pegasosppc/download/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show images of various formats

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_SDL=	image gfx
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-lSDL -lSDL_image -lSDL_gfx -L${LOCALBASE}/lib ${PTHREAD_LIBS}
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/shim

post-extract:
	@${RM} ${WRKSRC}/SDL_rotozoom.[ch]

post-patch:
	@${REINPLACE_CMD} -e '/SDL_rotozoom/s|\.c|.h|' ${WRKSRC}/shim.c

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o shim shim.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/shim ${PREFIX}/bin/

.include <bsd.port.mk>
