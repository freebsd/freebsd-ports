# New ports collection makefile for:	rubix
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	rubix
PORTVERSION=	1.0.5
CATEGORIES=	games
MASTER_SITES=	http://sed.free.fr/rubix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another Rubik's cube game with a rather interesting interface

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DENGLISH" \
		XINC="-I${X11BASE}/include" XLIB="-L${X11BASE}/lib -lX11"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	${DOCFILES}
PLIST_FILES=	bin/rubix

DOCFILES=	AUTHORS BUGS INSTALL README TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rubix ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
