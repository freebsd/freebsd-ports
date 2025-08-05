PORTNAME=	powa-web
PORTVERSION=	5.0.2
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL Workload Analyzer is a performance tool for PostgreSQL
WWW=		https://powa.readthedocs.org/

LICENSE=	PostgreSQL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=1.0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=2.0:www/py-tornado@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	powa-team

NO_ARCH=	yes

post-patch:
		${REINPLACE_CMD} 's,/etc/powa-web.conf,${PREFIX}/etc/powa-web.conf,' ${WRKSRC}/powa/options.py

.include <bsd.port.mk>
