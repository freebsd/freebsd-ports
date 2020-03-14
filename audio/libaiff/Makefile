# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libaiff
PORTVERSION=	5.0
DISTVERSIONSUFFIX=	-release
CATEGORIES=	audio
MASTER_SITES=	SF/aifftools/${PORTNAME}/LibAiff%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read and write AIFF files

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	lib/${PORTNAME}.a include/${PORTNAME}/config.h include/${PORTNAME}/endian.h \
		include/${PORTNAME}/${PORTNAME}.h include/${PORTNAME}/config.vc.h

.include <bsd.port.mk>
