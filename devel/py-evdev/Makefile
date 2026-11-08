PORTNAME=	evdev
PORTVERSION=	1.9.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Bindings to the Linux input handling subsystem
WWW=		https://pypi.org/project/evdev/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
