PORTNAME=	hidraw
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to gather hidraw information
WWW=		https://github.com/daym/hidraw/

LICENSE=	BSD2CLAUSE

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	daym
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/hidraw/_hidraw*.so

.include <bsd.port.mk>
