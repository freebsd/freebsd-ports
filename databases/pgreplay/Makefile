# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	pgreplay
DISTVERSIONPREFIX=	${PORTNAME:tu}_
DISTVERSION=	1_2_0
CATEGORIES=	databases

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Replay SQL statements from a Postgresql Log

LICENSE=	PostgreSQL

USE_GITHUB=	yes
GH_ACCOUNT=	laurenz

USES=		pgsql autoreconf
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pgreplay man/man1/pgreplay.1.gz

ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgreplay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pgreplay.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
