# Created by: James Howard <howardj@wam.umd.edu>
# $FreeBSD$

PORTNAME=	cursive
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://puck.nether.net/pub/janc/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create ASCII character cursive handwriting

PLIST_FILES=	bin/cursive \
		man/man6/cursive.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cursive ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cursive.6 ${STAGEDIR}${PREFIX}/man/man6

.include <bsd.port.mk>
