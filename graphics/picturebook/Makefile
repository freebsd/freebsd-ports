# New ports collection Makefile for:	pictureboook
# Date created:			    	25 December 2000
# Whom:				    	Takanori Watanabe <takawata@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	picturebook
PORTVERSION=	20010422
CATEGORIES=	graphics
MASTER_SITES=	http://samba.org/picturebook/
DISTNAME=	capture
EXTRACT_SUFX=  .tgz

MAINTAINER= alan@clegg.com

WRKSRC=		${WRKDIR}/picturebook
USE_IMLIB=yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/capture ${PREFIX}/bin/capture
	${MKDIR} ${PREFIX}/share/doc/picturebook
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/picturebook/README
.if!defined(NOPORTDOCS)
	${INSTALL_MAN} ${PATCHDIR}/README.FreeBSD ${PREFIX}/share/doc/picturebook/README.FreeBSD
.endif
.include <bsd.port.mk>
