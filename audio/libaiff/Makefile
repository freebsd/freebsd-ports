# New ports collection makefile for:	libaiff
# Date created:		14 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libaiff
PORTVERSION=	5.0
CATEGORIES=	audio
MASTER_SITES=	SF/aifftools/${PORTNAME}/LibAiff%20${PORTVERSION}
DISTNAME=	libaiff-5.0-release

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Read and write AIFF files

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	lib/${PORTNAME}.a include/${PORTNAME}/config.h include/${PORTNAME}/endian.h \
		include/${PORTNAME}/${PORTNAME}.h include/${PORTNAME}/config.vc.h
PLIST_DIRS=	include/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/install: libaiff.a/install:/' \
	${WRKSRC}/${MAKEFILE}.in

.if ${OSVERSION} < 700042
BROKEN=		does not build on 6.x.
.endif

.include <bsd.port.post.mk>
