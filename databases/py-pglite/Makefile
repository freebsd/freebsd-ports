PORTNAME=	pglite
DISTVERSION=	1.0.13
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Light PostgreSQL: use PostgreSQL as a simple SQLite database
WWW=		https://github.com/Oslandia/pglite

LICENSE=	LGPL20+

USES=		python pgsql
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
WANT_PGSQL=	server

post-patch:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' ${WRKSRC}/script/pglite

.include <bsd.port.mk>
