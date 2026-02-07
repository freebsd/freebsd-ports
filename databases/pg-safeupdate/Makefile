PORTNAME=	pg-safeupdate
PORTVERSION=	1.5
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	lukas.engelhardt@gmx.de
COMMENT=	PostgreSQL extension to block unconditional UPDATE/DELETE

LICENSE=	PostgreSQL

USES=		gmake pgsql
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	eradman

PLIST_FILES=	lib/postgresql/safeupdate.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/safeupdate.so

.include <bsd.port.mk>
