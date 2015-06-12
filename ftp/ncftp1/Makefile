# Created by: jkh
# $FreeBSD$

PORTNAME=	ncftp
PORTVERSION=	1.9.5
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/
PKGNAMESUFFIX=	1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP replacement with advanced user interface

BROKEN=		Unfetchable
OPTIONS_DEFINE=	AS_NCFTP
AS_NCFTP_DESC=	Install binary as ncftp instead of ncftp1

.include <bsd.port.options.mk>

NCFTP=	${PORTNAME}
.if empty(PORT_OPTIONS:MAS_NCFTP)
NCFTP:=	${NCFTP}${PKGNAMESUFFIX}
.endif

PLIST_FILES=	bin/${NCFTP} man/man1/${NCFTP}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${NCFTP}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${NCFTP}.1.gz

.include <bsd.port.mk>
