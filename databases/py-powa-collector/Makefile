PORTNAME=	powa-collector
DISTVERSION=	1.3.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Performs powa snapshots for remote servers
WWW=		https://powa.readthedocs.io/en/stable/components/powa-collector/

LICENSE=	PostgreSQL
LICENSE_FILE=   ${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:databases/py-psycopg2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

USE_GITHUB=     yes
GH_ACCOUNT=     powa-team

PLIST_FILES=	"@sample etc/powa-collector.conf.sample"
USE_RC_SUBR=	${PORTNAME}

post-patch:
		@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/powa_collector/options.py

post-install:
		${INSTALL_DATA} ${WRKSRC}/powa-collector.conf-dist ${STAGEDIR}${PREFIX}/etc/powa-collector.conf.sample

.include <bsd.port.mk>
