# New ports collection makefile for:	hnb
# Date created:				Fri Jul  6 05:37:14 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	hnb
PORTVERSION=	1.9.8
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_GMAKE=	yes
ALL_TARGET=

MAN1=		hnb.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hnb ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/../doc/hnb.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
