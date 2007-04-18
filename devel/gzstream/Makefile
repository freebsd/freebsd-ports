# New ports collection makefile for:	gzstream
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gzstream
DISTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Provides zlib functionality in an iostream

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	lib/lib${PORTNAME}.a include/${PORTNAME}.h
ALL_TARGET=	default

post-patch:
	@${REINPLACE_CMD} -e 's/=/?=/;s/$${AR}/$${AR} cr/' ${WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib${PORTNAME}.a ${PREFIX}/lib/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${PREFIX}/include/

.include <bsd.port.mk>
