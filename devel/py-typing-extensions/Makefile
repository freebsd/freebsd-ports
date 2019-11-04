# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	typing-extensions
PORTVERSION=	3.7.4.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	typing_extensions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backported and Experimental Type Hints for Python 3.5+

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_TYPING}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
