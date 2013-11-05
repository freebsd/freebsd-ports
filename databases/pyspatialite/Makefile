# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pyspatialite
PORTVERSION=	3.0.1
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP:pyspatialite \
		http://www.gaia-gis.it/gaia-sins/libspatialite-sources/:amalgam
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:pyspatialite \
		${AMALGAMATION_NAME}${EXTRACT_SUFX}:amalgam

MAINTAINER=	coder@tuxfamily.org
COMMENT=	DB-API 2.0 interface for SQLite 3.x with Spatialite 3.x

LIB_DEPENDS=	spatialite:${PORTSDIR}/databases/spatialite

USES=		iconv
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pyspatialite

AMALGAMATION_NAME=	libspatialite-amalgamation-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
ICONV_APPEND=
.else
ICONV_APPEND=	,'iconv'
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|pyspatialite-doc|${DOCSDIR}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%ICONV%%|${ICONV_APPEND}|" ${WRKSRC}/setup.py
	@${MV} ${WRKDIR}/${AMALGAMATION_NAME} ${WRKSRC}/amalgamation

.include <bsd.port.post.mk>
