# New ports collection makefile for:	xdigger
# Date created:				29 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xdigger
PORTVERSION=	1.0.10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
MAN6=		xdigger.6
MANCOMPRESSED=	no

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/configure.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdigger ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xdigger.man ${PREFIX}/man/man6/xdigger.6
	@${MKDIR} ${PREFIX}/share/xdigger
	${INSTALL_DATA} ${WRKSRC}/xdigger.level ${PREFIX}/share/xdigger
	${INSTALL_DATA} ${WRKSRC}/audio/*.au ${PREFIX}/share/xdigger
	@${TOUCH} ${PREFIX}/share/xdigger/xdigger.hiscore
	@${CHMOD} a+rw ${PREFIX}/share/xdigger/xdigger.hiscore
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xdigger
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xdigger
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xdigger
.endif

.include <bsd.port.mk>
