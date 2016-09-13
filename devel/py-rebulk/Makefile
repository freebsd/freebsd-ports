# Created by: Andrej Ebert <andrej@ebert.su>
# $FreeBSD$

PORTNAME=	rebulk
PORTVERSION=	0.7.4
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	andrej@ebert.su
COMMENT=	Python library that performs advanced searches in strings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Toilal

post-patch:
	@${REINPLACE_CMD} -e '/setup_requires/d' ${WRKSRC}/${PYSETUP}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
