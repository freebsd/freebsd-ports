# $FreeBSD$

PORTNAME=	backports.shutil_get_terminal_size
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Backport of the get_terminal_size function from Python 3.3's shutil

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports>0:devel/py-backports@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

POST_PLIST=	trim-backports-namespace

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__init__.py*
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__pycache__

trim-backports-namespace:
	@${REINPLACE_CMD} '/backports\/__init__.py*/d' ${TMPPLIST}
	@${REINPLACE_CMD} '/backports\/__pycache__*/d' ${TMPPLIST}

.include <bsd.port.mk>
