# New ports collection makefile for:	xenon
# Date created:				22 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	xenon
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://sydney.proximity.com.au/~ben/xenon/dist/ \
		ftp://yankee.proximitygroup.com/pub/xenon/

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Simple X-based text editor

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
MAKEFILE=	${WRKSRC}/makefiles/Makefile.Linux

MAN1=		xe.1

FIX_FILES=	Xe.h XeApp.h XeFontTable.C XeFontTable.h XeKeyTable.C \
		XeKeyTable.h XeObjectTable.h

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

do-configure:
.for file in ${FIX_FILES}
	@${REINPLACE_CMD} -e 's|#include <ext/|#include <|' \
		-e 's|ulong|u_long|g' -e 's|uint|u_int|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xe.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/examples/xe
	${INSTALL_DATA} ${WRKSRC}/xerc ${PREFIX}/share/examples/xe/sample.xerc

.include <bsd.port.post.mk>
