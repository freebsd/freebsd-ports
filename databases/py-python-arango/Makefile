# $FreeBSD$

PORTNAME=	python-arango
DISTVERSION=	3.12.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python driver for ArangoDB

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

post-extract:
	@${RM} -r ${WRKSRC}/tests  # otherwise they are installed under the root directory and cause conflicts

.include <bsd.port.mk>
