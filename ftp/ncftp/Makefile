# ex:ts=8
# Ports collection makefile for:  ncftp
# Date created:			  20 Jun 1996
# Whom:				  jkh
#
# $FreeBSD$
#

PORTNAME=	ncftp1
PORTVERSION=	1.9.5
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/
DISTNAME=	ncftp-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	FTP replacement with advanced user interface

.if defined(INSTALL_AS_NCFTP)
LATEST_LINK=	ncftp
.else
LATEST_LINK=	ncftp1
.endif
PLIST_FILES=	bin/${LATEST_LINK}
MAN1=		ncftp.1

pre-fetch:
	@${ECHO} ""
	@${ECHO} "Use INSTALL_AS_NCFTP=yes to install ncftp1 as ${PREFIX}/bin/ncftp"
	@${ECHO} ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/${LATEST_LINK}
	cd ${WRKSRC}; ${INSTALL_MAN} ncftp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
