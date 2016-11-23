# $FreeBSD$

PORTNAME=	${ORIGNAME:tl}
DISTVERSION=	0.7.7
CATEGORIES=	devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/${ORIGNAME}/${DISTVERSION:R}/
DISTNAME=	${ORIGNAME}-${DISTVERSION}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Set of client tools to use with Review Board

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.8.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

ORIGNAME=	RBTools

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
