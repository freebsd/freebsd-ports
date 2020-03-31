# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clikit
PORTVERSION=	0.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities to build beautiful and testable command line interfaces

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}pastel>=0.2.0:devel/py-pastel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylev>=1.3<2.0:devel/py-pylev@${PY_FLAVOR} \
		${PY_TYPING}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}woops>=0.2.1<0.3.0:devel/py-woops@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
