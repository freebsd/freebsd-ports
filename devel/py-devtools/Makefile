PORTNAME=	devtools
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Debug print command and other development tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asttokens>=2.0.0<3.0.0:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}executing>=0.8.0<1.0.0:devel/py-executing@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PYGMENTS
PYGMENTS_DESC=	Highlighted output support

PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=2.2.0:textproc/py-pygments@${PY_FLAVOR}

.include <bsd.port.mk>
