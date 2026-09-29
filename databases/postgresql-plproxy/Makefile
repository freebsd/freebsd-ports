PORTNAME=	plproxy
PORTVERSION=	2.12.0
CATEGORIES=	databases
MASTER_SITES=	https://plproxy.github.io/downloads/files/${PORTVERSION}/ \
		https://github.com/plproxy/plproxy/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Function-based sharding for PostgreSQL
WWW=		https://plproxy.github.io/ \
		https://github.com/plproxy/plproxy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		bison gmake pgsql

LLD_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plproxy.so

.include <bsd.port.mk>
