PORTNAME=	python-swiftclient
PORTVERSION=	3.13.1
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python client library for OpenStack Object Storage (Swift)
WWW=		https://launchpad.net/python-swiftclient

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.5.21:devel/py-pbr@${PY_FLAVOR}

RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.1:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/manpages/swift.1 \
	    ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
