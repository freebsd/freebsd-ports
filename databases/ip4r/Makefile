PORTNAME=	ip4r
PORTVERSION=	2.4.2
CATEGORIES=	databases net

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	IP address and IP range index types for PostgreSQL
WWW=		https://github.com/RhodiumToad/ip4r

LICENSE=	PostgreSQL

USES=		gmake pgsql
USE_GITHUB=	yes
GH_ACCOUNT=	RhodiumToad

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/postgresql/server/extension/ip4r
	${INSTALL_DATA} ${WRKSRC}/src/ipr.h ${STAGEDIR}${PREFIX}/include/postgresql/server/extension/ip4r
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/ip4r.so

.include <bsd.port.mk>
