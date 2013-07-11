# New ports collection makefile for:	py-curl
# Date created:				2 July 2001
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.19.0
PORTREVISION=	2
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
USE_OPENSSL=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's@data_files=@#data_files=t@' \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog COPYING COPYING2 INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.if !defined(NOPORDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tests/* ${DATADIR}
.endif

.include <bsd.port.mk>
