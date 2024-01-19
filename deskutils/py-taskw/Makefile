PORTNAME=	taskw
DISTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	deskutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python bindings for your taskwarrior database
WWW=		https://github.com/ralphbean/taskw

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PATCH_SITES=    https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/pull/
PATCHFILES+=    168.patch:-p1

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kitchen>0:devel/py-kitchen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.3.4,<2:devel/py-nose@${PY_FLAVOR} \
		task:deskutils/taskwarrior

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	ralphbean
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
