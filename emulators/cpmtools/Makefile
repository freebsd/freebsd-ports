# Created by: joerg
# $FreeBSD$

PORTNAME=	cpmtools
PORTVERSION=	1.1
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/joerg
DISTNAME=	cpm-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Utility to transfer files from/to CP/M (R) diskettes

WRKSRC=		${WRKDIR}/cpm

CFLAGS+=	-Wno-return-type
MAKE_ARGS+=	PREFIX=${PREFIX} DFLAG="${CFLAGS}" \
		DEST="${STAGEDIR}${PREFIX}/bin" \
		HELPFILEDIR="${STAGEDIR}${PREFIX}/lib"

.include <bsd.port.mk>
