PORTNAME=		barman
DISTVERSIONPREFIX=	release/
DISTVERSION=		3.20.0
CATEGORIES=		databases
PKGNAMEPREFIX=		pg
PKGNAMESUFFIX=		${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Backup and recovery manager for PostgreSQL
WWW=		https://pgbarman.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.11.17,<0.13:devel/py-uv-build@${PY_FLAVOR}

RUN_DEPENDS=	rsync:net/rsync									\
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.4.2:databases/py-psycopg2@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}argcomplete>0:devel/py-argcomplete@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB

WANT_PGSQL=	client
NO_ARCH=	yes

USERS=		barman
GROUPS=		barman

.include <bsd.port.pre.mk>

pre-build:
.for f in src/barman/config.py \
	  docs/barman.conf \
	  docs/_build/man/barman-config-update.1 \
	  docs/_build/man/barman.1 \
	  docs/_build/man/barman.5
	${SED} -i -e "s@%%PREFIX%%@${PREFIX}@" ${WRKSRC}/${f}
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/barman.conf \
		${STAGEDIR}${ETCDIR}/barman.conf.sample

.include <bsd.port.post.mk>
