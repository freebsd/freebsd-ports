PORTNAME=		barman
DISTVERSIONPREFIX=	release/
DISTVERSION=		3.11.1
CATEGORIES=		databases
PKGNAMEPREFIX=		pg
PKGNAMESUFFIX=		${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Backup and recovery manager for PostgreSQL
WWW=		https://pgbarman.org/

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync									\
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.4.2:databases/py-psycopg2@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR}		\
		${PYTHON_PKGNAMEPREFIX}argcomplete>0:devel/py-argcomplete@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB

WANT_PGSQL=	client
NO_ARCH=	yes

USERS=		barman
GROUPS=		barman

.include <bsd.port.pre.mk>

PGUSER=		pgsql

post-patch:
	${SED} -i -e "s@%%PREFIX%%@${PREFIX}@" ${WRKSRC}/barman/config.py
	${SED} -i -e "s@%%PREFIX%%@${PREFIX}@" ${WRKSRC}/doc/barman.conf
	${SED} -i -e "s@%%PGUSER%%@${PGUSER}@" ${WRKSRC}/doc/barman.5

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/barman.conf \
		${STAGEDIR}${ETCDIR}/barman.conf.sample

.include <bsd.port.post.mk>
