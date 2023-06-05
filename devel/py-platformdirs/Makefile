PORTNAME=	platformdirs
PORTVERSION=	3.5.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for determining appropriate platform-specific dirs
WWW=		https://github.com/platformdirs/platformdirs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.3:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.14.1:devel/py-hatchling@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.4:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-patch:
	@${RM} ${WRKSRC}/src/platformdirs/__init__.py.orig

.include <bsd.port.post.mk>
