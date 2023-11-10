PORTNAME=	keep-presence
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.7
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Prevent system from becoming idle
WWW=		https://github.com/carrot69/keep-presence

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/../LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pynput>0:x11/py-pynput@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	carrot69

WRKSRC_SUBDIR=	src

NO_ARCH=	yes

POST_PLIST=	fix-plist

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/keep-presence.py ${STAGEDIR}${PREFIX}/bin/keep-presence

fix-plist:
	@${REINPLACE_CMD} -e "s|bin/keep-presence\.py|bin/keep-presence|" ${TMPPLIST}

.include <bsd.port.mk>
