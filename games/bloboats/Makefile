# New ports collection makefile for:	bloboats
# Date created:				16 Sep 2006
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bloboats
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://mirror.kapsi.fi/bloboats.dy.fi/ \
		http://koti.mbnet.fi/makegho/c/blobtrox/ \
		http://shoebox.ath.cx/~make/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A boat racing game in the spirit of Elasto Mania or X-Moto

USE_GMAKE=	yes
USE_SDL=	mixer image net sdl
USE_GL=		yes
MAKE_JOBS_SAFE=	yes

MAKE_ENV+=	DATADIR="${DATADIR}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
