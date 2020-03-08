# Created by: lbartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyspatialite
PORTVERSION=	3.0.1
DISTVERSIONSUFFIX=	-alpha-0
PORTREVISION=	7
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP/source/p/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	DB-API 2.0 interface for SQLite 3.x with Spatialite

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

LIB_DEPENDS=	libspatialite.so:databases/spatialite \
		libgeos_c.so:graphics/geos \
		libproj.so:graphics/proj \
		libfreexl.so:textproc/freexl

OPTIONS_DEFINE=	DOCS

USES=		iconv python:2.7
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
ICONV_APPEND=
.else
ICONV_APPEND=	,iconv
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|pyspatialite-doc|${DOCSDIR}|g" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%ICONV%%|${ICONV_APPEND}|" ${WRKSRC}/setup.cfg

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyspatialite/_spatialite.so

.include <bsd.port.post.mk>
