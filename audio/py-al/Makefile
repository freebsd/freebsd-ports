# $FreeBSD$

PORTNAME=	al
PORTVERSION=	0.1.0
CATEGORIES=	audio python
MASTER_SITES=	http://bitbucket.org/marcusva/py-al/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyAL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenAL bindings for Python

LICENSE=	PD ZLIB
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/doc/copying.rst

USES=		openal:al python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
