PORTNAME=	dulwich
PORTVERSION=	0.22.8
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	dulwich-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Git Library
WWW=		https://www.dulwich.io/ \
		https://github.com/jelmer/dulwich

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.25,1:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastimport>=0:devel/py-fastimport@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geventhttpclient>=0:devel/py-geventhttpclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=17.1:devel/py-setuptools@${PY_FLAVOR}

USES=		cargo cpe python:3.9+ shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest

CARGO_BUILD=	no
CARGO_INSTALL=	no

CPE_VENDOR=	dulwich_project

SHEBANG_FILES=	examples/*.py

OPTIONS_DEFINE=	DOCS EXAMPLES FASTIMPORT PARAMIKO
FASTIMPORT_DESC=Git fastimport support
PARAMIKO_DESC=	SSH2 support

FASTIMPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastimport>=0:devel/py-fastimport@${PY_FLAVOR}
PARAMIKO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial/*.txt ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
