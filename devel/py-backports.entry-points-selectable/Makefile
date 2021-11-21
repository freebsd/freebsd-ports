# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	backports.entry-points-selectable
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	backports.entry_points_selectable-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compatibility shim providing selectable entry points for older implementations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
