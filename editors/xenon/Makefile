# New ports collection makefile for:	xenon
# Date created:				22 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	xenon
PORTVERSION=	0.6.7
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.proximity.com.au/pub/xenon/

MAINTAINER=	jedgar@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		xe.1

pre-patch:
	@${CP} ${WRKSRC}/makefiles/Makefile.Linux ${WRKSRC}/makefiles/Makefile.FreeBSD

do-configure:
	@cd ${WRKSRC}; ${LN} -sf makefiles/Makefile.FreeBSD Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xe.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/examples/xe
	${INSTALL_DATA} ${WRKSRC}/xerc ${PREFIX}/share/examples/xe/sample.xerc

.include <bsd.port.mk>
