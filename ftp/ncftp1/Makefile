# Created by: jkh
# $FreeBSD$

PORTNAME=	ncftp
PORTVERSION=	1.9.5
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/
DISTNAME=	ncftp-${PORTVERSION}
PKGNAMESUFFIX=	1

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	FTP replacement with advanced user interface

PLIST_FILES=	bin/${LATEST_LINK}
MAN1=		ncftp.1

NO_STAGE=	yes
pre-fetch:
	@${ECHO} ""
	@${ECHO} "Use INSTALL_AS_NCFTP=yes to install ncftp1 as ${PREFIX}/bin/ncftp"
	@${ECHO} ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/${LATEST_LINK}
	cd ${WRKSRC}; ${INSTALL_MAN} ncftp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
