# New ports collection makefile for:	xataxx
# Date created:				4 July 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xataxx
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.freesoftware.com/pub/X11/R5contrib/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
MAN6=		xataxx.6
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xataxx ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xataxx.man ${PREFIX}/man/man6/xataxx.6
	@${MKDIR} ${PREFIX}/share/xataxx
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/xataxx
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xataxx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xataxx
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/xataxx
.endif

.include <bsd.port.mk>
