# $FreeBSD$

PORTNAME=	atftp
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/a/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.dfsg.orig

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Advanced tftp server and client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.dfsg

USE_RC_SUBR=	atftpd
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/atftp sbin/atftpd man/man1/atftp.1.gz man/man8/atftpd.8.gz

.include <bsd.port.mk>
