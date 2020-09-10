# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblas12
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Library For Reading And Writing LAS-Format Data

LICENSE=	BSD3CLAUSE BSL MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		autoreconf dos2unix gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libLAS
GH_PROJECT=	libLAS

pre-patch:
	${MV} ${WRKSRC}/include/liblas ${WRKSRC}/include/liblas12
	${MV} ${WRKSRC}/apps/las2las.c ${WRKSRC}/apps/las2las12.c
	${MV} ${WRKSRC}/apps/las2ogr.cpp ${WRKSRC}/apps/las2ogr12.cpp
	${MV} ${WRKSRC}/apps/las2txt.c ${WRKSRC}/apps/las2txt12.c
	${MV} ${WRKSRC}/apps/lasdiff.c ${WRKSRC}/apps/lasdiff12.c
	${MV} ${WRKSRC}/apps/lasinfo.c ${WRKSRC}/apps/lasinfo12.c
	${MV} ${WRKSRC}/apps/lasmerge.c ${WRKSRC}/apps/lasmerge12.c
	${MV} ${WRKSRC}/apps/liblas-config.in ${WRKSRC}/apps/liblas12-config.in
	${MV} ${WRKSRC}/apps/txt2las.c ${WRKSRC}/apps/txt2las12.c

.include <bsd.port.mk>
