PORTNAME=	powa-web
PORTVERSION=	4.1.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL Workload Analyzer is a performance tool for PostgreSQL

LICENSE=	PostgreSQL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=1.0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=2.0:www/py-tornado@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

post-patch:
		${REINPLACE_CMD} 's,/etc/powa-web.conf,${PREFIX}/etc/powa-web.conf,' ${WRKSRC}/powa/options.py

.include <bsd.port.mk>
