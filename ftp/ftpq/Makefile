# New ports collection makefile for:	ftpq
# Date created:				Mon 03 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	ftpq
PORTVERSION=	1.06
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	ftp
MASTER_SITES=	http://tranchant.plus.com/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Upload queue manager for non-permanent connections

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		ftpq.1
PLIST_SUB+=	SPOOLDIR=${SPOOLDIR}

# This may be set interactively at install-time:
SPOOLDIR?=	/var/spool/ftpq

post-patch:
	@ ${REINPLACE_CMD} -e 's#%%SPOOLDIR%%#${SPOOLDIR}#' \
	  ${WRKSRC}/Makefile.in ${WRKSRC}/src/ftpq.h

post-install:
	@ ${MKDIR} ${SPOOLDIR} && ${CHMOD} 777 ${SPOOLDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in CHANGELOG README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
