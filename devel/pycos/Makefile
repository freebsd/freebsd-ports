# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	pycos
PORTVERSION=	4.8.1
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Concurrent, Asynchronous, Distributed, Communicating Tasks with Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

post-patch:
	${FIND} ${WRKSRC} -name \*.py |	\
	    ${XARGS} ${GREP} -l darwin |\
	    ${XARGS} ${REINPLACE_CMD}	\
		"s,sys.platform == 'darwin',sys.platform.startswith('${OPSYS:tl}'),"

.include <bsd.port.mk>
