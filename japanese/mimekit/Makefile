# New ports collection makefile for:	mimekit
# Version required:		1.6
# Date created:			9 April 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1997/05/07 23:40:58 max Exp $
#

DISTNAME=	mimekit1.6
PKGNAME=	ja-mimekit-1.6
CATEGORIES=	japanese devel mail
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/ccipr/DeleGate/ \
		ftp://ftp.iij.ad.jp/pub/mail/mime/

MAINTAINER=	max@FreeBSD.ORG

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mimekit
	${INSTALL_DATA} ${WRKSRC}/README.LIB ${PREFIX}/share/doc/mimekit
	${INSTALL_DATA} ${WRKSRC}/README.PGP ${PREFIX}/share/doc/mimekit
.endif

.include <bsd.port.mk>
