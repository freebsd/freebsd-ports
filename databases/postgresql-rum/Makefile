PORTNAME=	rum
PORTVERSION=	1.3.15
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Inverted index with additional information in posting lists
WWW=		https://github.com/postgrespro/rum

LICENSE=	PostgreSQL

USES=		gmake pgsql:11+

LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	postgrespro

WANT_PGSQL=	server

# As of rum 1.3.15 and pg18 the build behaves differently.
# The Makefile is including the PGXS Makefile framework
# so the "installheaders" target never gets hit because
# of USE_PGXS=1, but the Makefile doesn't work at all
# without it as it wants to includes relative paths that
# do not exist. The pgxs.mk supports installing headers
# declared in HEADERS and now installs to an extension-specific
# subdirectory. To ensure the headers are still available
# we now declare them here.
RUM_HEADERS=	src/rum.h src/rumsort.h

do-build:
	cd ${WRKSRC} && ${MAKE_CMD} USE_PGXS=1

do-install:
	cd ${WRKSRC} && \
	${MAKE_CMD} USE_PGXS=1 DESTDIR=${STAGEDIR} HEADERS="${RUM_HEADERS}" install

.include <bsd.port.mk>
