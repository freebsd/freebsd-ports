# New ports collection makefile for:	ftpcopy
# Date created:				5 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftpcopy
PORTVERSION=	0.4.5
CATEGORIES=	ftp
MASTER_SITES=	http://www.ohse.de/uwe/ftpcopy/

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/web/${DISTNAME}

MAN1=		ftpcopy.1 ftpcp.1 ftpls.1

do-install:
	cd ${WRKSRC}/compile && \
		${INSTALL_PROGRAM} ftpcopy ftpls ${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1 && \
		${INSTALL_SCRIPT} ftpcp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && \
	cd ${WRKSRC}/compile && \
		${INSTALL_DATA} ChangeLog NEWS LICENSES LICENSES.LOCAL \
			README THANKS ${DOCSDIR}
.endif

.include <bsd.port.mk>
