# Created by: hrs
# $FreeBSD$

PORTNAME=	icbirc
PORTVERSION=	1.8
CATEGORIES=	irc
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Proxy IRC client and ICB server

MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man/man"
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN8=		icbirc.8
MANCOMPRESSED=	maybe

PLIST_FILES=	bin/icbirc

NO_STAGE=	yes
.include <bsd.port.mk>
