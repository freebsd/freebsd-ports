# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	installer
PORTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	03

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for installing Python wheels

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:0\.3\.

.include <bsd.port.mk>
