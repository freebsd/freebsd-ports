PORTNAME=	novelWriter
DISTVERSIONPREFIX=	v
DISTVERSION=	26.2.2
PORTREVISION=	1
CATEGORIES=	editors python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Text editor designed for writing novels
WWW=		https://novelwriter.io/ \
		https://github.com/vkbo/novelwriter

LICENSE=	GPLv3+

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=3.3.0:textproc/py-enchant@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python pyqt:6
USE_PYQT=	pyqt6
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	vkbo
GH_PROJECT=	novelWriter

NO_ARCH=	yes

post-configure: # compile translation files
	@cd ${WRKSRC} && ${PYTHON_CMD} pkgutils.py qtlrelease

.include <bsd.port.mk>
