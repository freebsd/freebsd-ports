PORTNAME=	pgreplay
DISTVERSIONPREFIX=	${PORTNAME:tu}_
DISTVERSION=	1_5_0
CATEGORIES=	databases

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Replay SQL statements from a Postgresql Log
WWW=		https://github.com/laurenz/pgreplay

LICENSE=	PostgreSQL

USES=		pgsql autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	laurenz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pgreplay share/man/man1/pgreplay.1.gz

ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgreplay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pgreplay.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
