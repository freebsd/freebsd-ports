PORTNAME=	importlib-resources
PORTVERSION=	5.4.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	importlib_resources-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Read resources from Python packages

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zipp>=3.1.0:devel/py-zipp@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
