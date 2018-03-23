# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stevedore
PORTVERSION=	1.28.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Manage dynamic plugins for Python applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
