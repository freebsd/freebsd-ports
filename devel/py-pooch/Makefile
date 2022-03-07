# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pooch
PORTVERSION=	1.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fetch your sample data files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
xRUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.3.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19.0:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PROGRESS SFTP XXHASH
OPTIONS_DEFAULT=PROGRESS SFTP XXHASH
PROGRESS_DESC=	Progress bar support
SFTP_DESC=	SFTP download support
XXHASH_DESC=	Hash algorithm support

PROGRESS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tqdm>=4.41.0<5.0.0:misc/py-tqdm@${PY_FLAVOR}
SFTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=2.7.0:security/py-paramiko@${PY_FLAVOR}
XXHASH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xxhash>=1.4.3:devel/py-xxhash@${PY_FLAVOR}

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
