PORTNAME=	setuptools-gettext
DISTVERSION=	0.1.18
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	setuptools_gettext-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Setuptools plugin for gettext
WWW=		https://github.com/breezy-team/setuptools-gettext

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		gettext-tools python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
