# New ports collection makefile for:	ftpq
# Date created:				Mon 03 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	ftpq
PORTVERSION=	1.05
PORTEPOCH=	1
CATEGORIES=	ftp
MASTER_SITES=	http://www.tranchant.freeserve.co.uk/software/

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		ftpq.1
SPOOLDIR?=	/var/spool/ftpq
PLIST_SUB+=	SPOOLDIR=${SPOOLDIR}

post-patch:
	@ ${PERL} -pi -e 's#%%SPOOLDIR%%#${SPOOLDIR}#' \
	  ${WRKSRC}/Makefile.in ${WRKSRC}/src/ftpq.h

post-install:
	@ ${MKDIR} ${SPOOLDIR} && ${CHMOD} 777 ${SPOOLDIR}

.include <bsd.port.mk>
