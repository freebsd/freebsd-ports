# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-swiftclient
PORTVERSION=	3.2.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Python client library for OpenStack Object Storage (Swift)

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.5.21:devel/py-pbr

RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>=3.0:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}requests>=1.1:www/py-requests

USES=		python:2
USE_PYTHON=	distutils autoplist

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/manpages/swift.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
