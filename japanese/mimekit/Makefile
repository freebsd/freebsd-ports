# New ports collection makefile for:	mimekit
# Version required:		1.7
# Date created:			9 April 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	mimekit1.7
PKGNAME=	ja-mimekit-1.7
CATEGORIES=	japanese devel mail
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/ccipr/DeleGate/ \
		ftp://ftp.iij.ad.jp/pub/mail/mime/

MAINTAINER=	max@FreeBSD.org

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mimekit
	${INSTALL_DATA} ${WRKSRC}/README.LIB ${PREFIX}/share/doc/mimekit
	${INSTALL_DATA} ${WRKSRC}/README.PGP ${PREFIX}/share/doc/mimekit
.endif

.include <bsd.port.mk>
