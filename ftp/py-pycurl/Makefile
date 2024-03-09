PORTNAME=	pycurl
PORTVERSION=	7.45.3
CATEGORIES=	ftp python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to libcurl
WWW=		http://pycurl.io/ \
		https://github.com/pycurl/pycurl

LICENSE=	LGPL21 MIT
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL
LICENSE_FILE_MIT=	${WRKSRC}/COPYING-MIT

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		python ssl
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
