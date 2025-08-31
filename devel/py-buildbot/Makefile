PORTNAME=	buildbot
DISTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Continuous Integration Framework
WWW=		https://buildbot.net

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alembic>=1.6.0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}autobahn>=0.16.0:www/py-autobahn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-www>=${PORTVERSION}:devel/py-buildbot-www@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter2>=1.3.0:sysutils/py-croniter2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.6.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=1.5:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4.0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}treq>=20.9:www/py-treq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=22.1.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txaio>=2.2.2:devel/py-txaio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidiff>=0.7.5:devel/py-unidiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.1.1:devel/py-zope.interface@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.0.0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moto>0:devel/py-moto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypugjs>0:devel/py-pypugjs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>0:www/py-requests-futures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}treq>0:www/py-treq@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	buildbot

USERS=	${PORTNAME}
GROUPS=	${PORTNAME}

NO_ARCH=	yes
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_VER=${PYTHON_VER}

# the directory was removed, but MANIFEST.in still references it
# https://github.com/buildbot/buildbot/commit/9251a994e7ba5f8ab9e678b49920bdc38cd52b3d
BUILDBOT_REMOVE_ME=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/buildbot/reporters/templates
POST_PLIST+=		fix-plist

OPTIONS_DEFINE=		BROTLI CONFIGURABLE DOCS ZSTD
OPTIONS_DEFAULT=	BROTLI CONFIGURABLE ZSTD

CONFIGURABLE_DESC=	Enable configurable buildbot

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.1.0:archivers/py-brotli@${PY_FLAVOR}
CONFIGURABLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}evalidate>=2.0.0:math/py-evalidate@${PY_FLAVOR}
ZSTD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0.23.0:archivers/py-zstandard@${PY_FLAVOR}

fix-plist:
	${REINPLACE_CMD} -e 's|^${BUILDBOT_REMOVE_ME}$$||' ${TMPPLIST}
	${REINPLACE_CMD} -e '/^buildbot/d' ${TMPPLIST}

post-install:
	${RM} -r ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/buildbot/reporters/templates
	${RM} -rf ${STAGEDIR}${PREFIX}/buildbot

do-test:
	@cd ${WRKSRC} && PYTHONPATH=${WRKSRC} TZ=UTC ${LOCALBASE}/bin/trial-${PYTHON_VER} buildbot

# Old invocation that we will probably need later
# ${MKDIR} ${WRKDIR}/tmp
# cd ${WRKDIR}/tmp && TZ=UTC LANG=C PYTHONPATH=${WRKSRC} ${PYTHON_CMD} -m twisted.trial buildbot.test

.include <bsd.port.mk>
