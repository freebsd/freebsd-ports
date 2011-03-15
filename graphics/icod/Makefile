# New ports collection makefile for:	icod
# Date created:				02 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	icod
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= jedgar
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to convert Windows icon files to xpm format

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PLIST_FILES=	bin/icod
WRKSRC=		${WRKDIR}/icod
ALL_TARGET=	icod

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/icod ${PREFIX}/bin

.include <bsd.port.mk>
