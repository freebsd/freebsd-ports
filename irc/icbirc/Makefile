# Created by: hrs
# $FreeBSD$

PORTNAME=	icbirc
PORTVERSION=	2.1
CATEGORIES=	irc
MASTER_SITES=	http://www.benzedrine.ch/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Proxy IRC client and ICB server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${FILESDIR}/COPYING

USES=		uidfix
MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man/man"
PLIST_FILES=	bin/icbirc \
		man/man8/icbirc.8.gz

.include <bsd.port.mk>
