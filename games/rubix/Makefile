# New ports collection makefile for:	rubix
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	rubix
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://sed.free.fr/rubix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another Rubik's cube game with a rather interesting interface

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DENGLISH" \
		XINC="-I${X11BASE}/include" XLIB="-L${X11BASE}/lib -lX11"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rubix ${PREFIX}/bin
.if !defined(NOPORTDOCS)
.for file in AUTHORS BUGS INSTALL README TODO
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
