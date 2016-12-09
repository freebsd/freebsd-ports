# Created by: Wen Heping <wenhping@gmail.com>
# $FreeBSD$

PORTNAME=	cython
PORTVERSION=	0.25.2
CATEGORIES=	lang python
MASTER_SITES=	http://www.cython.org/release/ \
		CHEESESHOP
DISTNAME=	Cython-${PORTVERSION}

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Compiler for Writing C Extensions for the Python Language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
