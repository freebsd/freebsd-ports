# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	py-jack
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for the Jack Audio Server

LICENSE=	GPLv2

LIB_DEPENDS=	libjack.so:audio/jack
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

USES=		python:-2.7 localbase
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e \
		's|"/usr/local/|"${LOCALBASE}/|; \
		 s|"jack", "dl"|"jack"|; \
		 s|os.system.*|pass|' \
		${WRKSRC}/setup.py
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jack.so

.include <bsd.port.mk>
