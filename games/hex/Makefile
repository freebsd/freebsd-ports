# New ports collection makefile for:	Hex
# Date created:		9 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	hex
PORTVERSION=	0.0.2
CATEGORIES=	games
MASTER_SITES=	http://www.nott.ac.uk/~psystrj/ \
		http://www.psn.net/~andrews/dist/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_X_PREFIX=	YES
USE_GMAKE=	YES
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hex ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/hex/graphics
.for i in 0 1 2 3 4 5 6 7 8
	${INSTALL_DATA} ${WRKSRC}/graphics/ball${i}.png \
			 ${PREFIX}/share/hex/graphics/ball${i}.png
.endfor
	@${MKDIR} ${PREFIX}/share/hex/levels
	${INSTALL_DATA} ${WRKSRC}/levels/Level1 \
			 ${PREFIX}/share/hex/levels/Level1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/hex
.for file in HISTORY README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hex
.endfor
.endif

.include <bsd.port.mk>
