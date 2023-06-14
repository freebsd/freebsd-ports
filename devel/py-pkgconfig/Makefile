PORTNAME=	pkgconfig
PORTVERSION=	1.5.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interface Python with pkg-config
WWW=		https://github.com/matze/pkgconfig

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig:run python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
