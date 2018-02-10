# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdis
PORTVERSION=	3.6.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-Python bytecode Disassembler and Marshal routines

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE.gpl2
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.mit

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
