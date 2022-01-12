# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	bitcoin
DISTVERSION=	1.1.42
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Bitcoin Tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

POST_PLIST=	fix-plist

fix-plist:
	@${REINPLACE_CMD} -e "s|^LICENSE$$||" ${TMPPLIST}

post-install:
	${RM} ${STAGEDIR}${PREFIX}/LICENSE

.include <bsd.port.mk>
