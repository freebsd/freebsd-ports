# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	stevedore
PORTVERSION=	3.5.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Manage dynamic plugins for Python applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# pbr is a RUN_DEPENDS too, just declared elsewhere (requirements.txt)
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234529
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=197373
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=1.7.0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
