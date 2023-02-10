PORTNAME=	fastbencode
PORTVERSION=	0.0.9
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Fast implementation of bencode
WWW=		https://github.com/breezy-team/fastbencode

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/fastbencode/*.so

.include <bsd.port.mk>
