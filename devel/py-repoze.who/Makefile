# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	repoze.who
PORTVERSION=	2.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Identification and authentication framework for WSGI

LICENSE=	REPOZE
LICENSE_NAME=	Repoze License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webob>=0:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.5.2:devel/py-zope.interface@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
