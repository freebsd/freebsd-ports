# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	dispy
PORTVERSION=	4.10.4
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Distributed and Parallel Computing with/for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycos>=4.8.0:devel/pycos@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
