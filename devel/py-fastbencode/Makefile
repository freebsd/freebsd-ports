PORTNAME=	fastbencode
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Fast implementation of bencode
WWW=		https://github.com/breezy-team/fastbencode

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on expired lang/cython0
EXPIRATION_DATE=2026-09-15

USES=		python
USE_PYTHON=	autoplist cython0 distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/fastbencode/*.so

.include <bsd.port.mk>
