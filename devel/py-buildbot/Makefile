# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	buildbot
PORTVERSION=	2.10.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Continuous Integration Framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}autobahn>=0.16.0:www/py-autobahn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=17.9.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.1.1:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=1.2.0<1.4:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.13:databases/py-sqlalchemy-migrate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txaio>=2.2.2:devel/py-txaio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}treq>0:www/py-treq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txrequests>0:www/py-txrequests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-pkg>0:devel/py-buildbot-pkg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjade>0:textproc/py-pyjade@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moto>0:devel/py-moto@${PY_FLAVOR}

USES=		python:3.5+
USE_RC_SUBR=	buildbot
USE_PYTHON=	autoplist concurrent distutils

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && PYTHONPATH=${WRKSRC} TZ=UTC ${LOCALBASE}/bin/trial-${PYTHON_VER} buildbot

# Old invocation that we will probably need later
# ${MKDIR} ${WRKDIR}/tmp
# cd ${WRKDIR}/tmp && TZ=UTC LANG=C PYTHONPATH=${WRKSRC} ${PYTHON_CMD} -m twisted.trial buildbot.test

.include <bsd.port.mk>
