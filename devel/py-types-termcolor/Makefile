PORTNAME=	types-termcolor
PORTVERSION=	1.1.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Typing stubs for termcolor
WWW=		https://pypi.org/project/types-termcolor/

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

# XXX: no longer needed with termcolor>=2.0.0, remove after its update
CONFLICTS=	${PYTHON_PKGNAMEPREFIX}termcolor-2*

.include <bsd.port.mk>
