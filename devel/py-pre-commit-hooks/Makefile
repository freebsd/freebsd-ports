PORTNAME=	pre-commit-hooks
PORTVERSION=	4.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pre_commit_hooks-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Some out-of-the-box hooks for pre-commit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
