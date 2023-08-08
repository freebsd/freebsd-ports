PORTNAME=	bitcoin
DISTVERSION=	1.1.42
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Bitcoin Tools
WWW=		https://github.com/vbuterin/pybitcointools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

POST_PLIST=	fix-plist

fix-plist:
	@${REINPLACE_CMD} -e "s|^LICENSE$$||" ${TMPPLIST}

post-install:
	${RM} ${STAGEDIR}${PREFIX}/LICENSE

.include <bsd.port.mk>
