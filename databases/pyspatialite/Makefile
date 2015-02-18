# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pyspatialite
PORTVERSION=	3.0.1
PORTREVISION=	5
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP:pyspatialite
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}-alpha-0${EXTRACT_SUFX}:pyspatialite

MAINTAINER=	coder@tuxfamily.org
COMMENT=	DB-API 2.0 interface for SQLite 3.x with Spatialite

LIB_DEPENDS=	libspatialite.so:${PORTSDIR}/databases/spatialite \
		libgeos_c.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libfreexl.so:${PORTSDIR}/textproc/freexl
		

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-alpha-0

USES=		iconv python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	pyspatialite


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
.include <bsd.port.post.mk>
