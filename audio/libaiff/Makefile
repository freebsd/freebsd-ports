# New ports collection makefile for:	libaiff
# Date created:		14 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libaiff
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	SF/aifftools

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Read and write AIFF files

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/${PORTNAME}.a include/${PORTNAME}/config.h include/${PORTNAME}/endian.h \
		include/${PORTNAME}/${PORTNAME}.h
PLIST_DIRS=	include/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's/install: libaiff.a/install:/' ${WRKSRC}/${MAKEFILE}.in

.include <bsd.port.mk>
