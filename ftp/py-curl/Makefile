# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.19.0
PORTREVISION=	3
CATEGORIES=	ftp python
MASTER_SITES=	http://pycurl.sourceforge.net/download/ \
		http://pycurl.sourceforge.net/download/00-OLD-VERSIONS/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python interface to libcurl

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

DOCSDIR=	${PREFIX}/share/doc/py-curl
EXAMPLESDIR=	${PREFIX}/share/examples/py-curl
DATADIR=	${PREFIX}/share/py-curl

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pycurl
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's@data_files=@#data_files=t@' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
