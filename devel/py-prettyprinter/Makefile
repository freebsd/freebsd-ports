# Created by: Patrice Clement <monsieurp@gentoo.org>

PORTNAME=	prettyprinter
PORTVERSION=	0.18.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	monsieurp@gentoo.org
COMMENT=	Syntax-highlighting, declarative and composable pretty printer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorful>=0.4.0:devel/py-colorful@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.2.0:textproc/py-pygments@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
