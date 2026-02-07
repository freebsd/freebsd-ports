PORTNAME=	icbirc
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.benzedrine.ch/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Proxy IRC client and ICB server
WWW=		https://www.benzedrine.ch/icbirc.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${FILESDIR}/COPYING

USES=		uidfix
MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/share/man/man"
PLIST_FILES=	bin/icbirc \
		share/man/man8/icbirc.8.gz

.include <bsd.port.mk>
