# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.19.5
CATEGORIES=	ftp python
MASTER_SITES=	CHEESESHOP \
		http://pycurl.sourceforge.net/download/ \
		http://pycurl.sourceforge.net/download/00-OLD-VERSIONS/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to libcurl

LICENSE=	LGPL21 MIT
LICENSE_COMB=	dual

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

PYTHON_FEATURES=autoplist,distutils
USES=		python

DATADIR=	${PREFIX}/share/py-curl
DOCSDIR=	${PREFIX}/share/doc/py-curl
EXAMPLESDIR=	${PREFIX}/share/examples/py-curl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pycurl.so

.include <bsd.port.mk>
