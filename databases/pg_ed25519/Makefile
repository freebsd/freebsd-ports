PORTNAME=	pg_ed25519
PORTVERSION=	0.2
CATEGORIES=	databases

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	PostgreSQL extension for ed25519 sign and verify

LICENSE=	MIT

USES=		gmake pgsql:9.4+
LLD_UNSAFE=	yes
WANT_PGSQL=	server

USE_GITLAB=	yes
GL_ACCOUNT=	dwagin
GL_COMMIT=	203944dbd3444257490eb30d2f6363e391a23a6b

PLIST_FILES=	lib/postgresql/pg_ed25519.so \
		share/postgresql/extension/pg_ed25519--${PORTVERSION}.sql \
		share/postgresql/extension/pg_ed25519.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_ed25519.so

.include <bsd.port.mk>
