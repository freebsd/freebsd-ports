# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swiftclient
PORTVERSION=	2.0.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Python client library for OpenStack Object Storage (Swift)

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.5.21:${PORTSDIR}/devel/py-pbr

RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}requests>=1.1:${PORTSDIR}/www/py-requests

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/manpages/swift.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
