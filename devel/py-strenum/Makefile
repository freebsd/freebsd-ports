PORTNAME=	StrEnum
DISTVERSION=	0.4.15
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Enum that inherits from str
WWW=		https://pypi.org/project/StrEnum/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils pytest

post-patch:
	@${REINPLACE_CMD} '/pytest-runner/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
