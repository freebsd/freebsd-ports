# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	iconv
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	converters python
MASTER_SITES=	LOCAL/perky
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Iconv wrapper with Unicode codec for Python

USES=		iconv python:2
USE_PYTHON=	autoplist distutils

.if empty(ICONV_LIB)
SETUPINFO=	,library_dirs=["${LOCALBASE}/lib"],\
		include_dirs=["${LOCALBASE}/include"]
.else
SETUPINFO=	,libraries=["iconv"],library_dirs=["${LOCALBASE}/lib"],\
		include_dirs=["${LOCALBASE}/include"]
.endif

post-patch:
	${REINPLACE_CMD} 's!^\(.*ext_mod.*\)\()]\)$$!\1${SETUPINFO}\2!g'\
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/iconv.so

.include <bsd.port.mk>
