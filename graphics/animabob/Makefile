# New ports collection makefile for:	animabob
# Date created:		21 July 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	animabob
PORTVERSION=	1.3.0b
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.borg.umn.edu/pub/lcse/grant/AnimaBob/

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Interactive 3D volume renderer

USE_IMAKE=	yes
USE_MESA=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
ALL_TARGET=	build

MAN1=		animabob.1 icol.1
MANCOMPRESSED=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -x -n 10 \
		${REINPLACE_CMD} -E \
			-e 's|malloc.h|stdlib.h|'

post-build:
# make the doc installation PREFIX safe
	@${REINPLACE_CMD} -E \
		-e 's|(DOCDIR[[:space:]]*=).*$$|\1${PREFIX}/lib/X11/doc|' \
		${WRKSRC}/doc/Makefile

.include <bsd.port.mk>
