PORTNAME=	pgjwt
PORTVERSION=	0.2.0.20230302
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	lukas.engelhardt@gmx.de
COMMENT=	PostgreSQL implementation of JSON Web Tokens
WWW=		https://github.com/michelp/pgjwt

LICENSE=	MIT

USES=		gmake pgsql
WANT_PGSQL=	server

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	michelp
GH_TAGNAME=	f3d82fd

.include <bsd.port.mk>
