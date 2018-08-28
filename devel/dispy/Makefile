# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	dispy
PORTVERSION=	4.9.1
PORTREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Distributed and Parallel Computing with/for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycos>=4.7.7:devel/pycos@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

post-patch:
	${FIND} ${WRKSRC} -name \*.py |	\
	    ${XARGS} ${GREP} -l darwin |\
	    ${XARGS} ${REINPLACE_CMD}	\
		"s,sys.platform == 'darwin',sys.platform.startswith('${OPSYS:tl}'),"

.include <bsd.port.mk>
