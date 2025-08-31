PORTNAME=	tahoe-lafs
DISTVERSION=	1.20.0
PORTREVISION=	1
CATEGORIES=	filesystems python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tahoe_lafs-${PORTVERSION}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Secure, decentralized, fault-tolerant file store
WWW=		https://tahoe-lafs.org

LICENSE=	GPLv2+ TGGPL
LICENSE_COMB=	dual
LICENSE_NAME_TGGPL=	Transitive Grace Period Public Licence 1.0
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_TGGPL=	${WRKSRC}/COPYING.TGPPL.rst
LICENSE_PERMS_TGGPL=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}autobahn>=0:www/py-autobahn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cbor2>=0:devel/py-cbor2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}collections-extended>=0:devel/py-collections-extended@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eliot>=0:devel/py-eliot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}foolscap>=0:devel/py-foolscap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}klein>=0:www/py-klein@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}magic-wormhole>=0:net/py-magic-wormhole@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycddl>=0:textproc/py-pycddl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrsistent>=0:devel/py-pyrsistent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyutil>=0:devel/py-pyutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}treq>=0:www/py-treq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zfec>=0:converters/py-zfec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		I2P TOR
OPTIONS_DEFAULT=	I2P TOR

I2P_DESC=	Enable support for I2P
TOR_DESC=	Enable support for Tor

I2P_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}txi2p-tahoe>=0:devel/py-txi2p-tahoe@${PY_FLAVOR}
TOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}txtorcon>=0:security/py-txtorcon@${PY_FLAVOR}

.include <bsd.port.mk>
