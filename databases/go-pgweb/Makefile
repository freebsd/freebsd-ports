PORTNAME=	pgweb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.7
PORTREVISION=	28
CATEGORIES=	databases www
PKGNAMEPREFIX=	go-

MAINTAINER=	daniel@morante.net
COMMENT=	Web-based database browser for PostgreSQL
WWW=		https://github.com/sosedoff/pgweb

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	sosedoff
USE_RC_SUBR=	${PORTNAME}

GO_PKGNAME=	github.com/sosedoff/pgweb

SUB_FILES+=	pkg-message
SUB_LIST+=	PGWEBGROUP=${GROUPS} \
		PGWEBUSER=${USERS} \
		PORTNAME=${PORTNAME}

PLIST_FILES=	bin/pgweb

USERS=		www
GROUPS=		www

.include <bsd.port.mk>
