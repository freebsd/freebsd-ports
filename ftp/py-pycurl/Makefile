# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pycurl
PORTVERSION=	7.21.5
CATEGORIES=	ftp python
MASTER_SITES=	CHEESESHOP \
		http://pycurl.sourceforge.net/download/ \
		http://pycurl.sourceforge.net/download/00-OLD-VERSIONS/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to libcurl

LICENSE=	LGPL21 MIT
LICENSE_COMB=	dual

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_PYTHON=	autoplist concurrent distutils
USES=		python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}.so

.include <bsd.port.mk>
