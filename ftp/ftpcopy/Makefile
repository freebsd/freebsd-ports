# New ports collection makefile for:	ftpcopy
# Date created:				5 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftpcopy
PORTVERSION=	0.4.0
CATEGORIES=	ftp
MASTER_SITES=	http://www.ohse.de/uwe/ftpcopy/

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/web/${DISTNAME}

MAN1=		ftpcopy.1 ftpcp.1 ftpls.1

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/compile && \
		${INSTALL_PROGRAM} ftpcopy ftpls ${PREFIX}/bin && \
		${INSTALL_SCRIPT} ftpcp ${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1 && \
		${INSTALL_DATA} NEWS README ${DATADIR}

.include <bsd.port.mk>
