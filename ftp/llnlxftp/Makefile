# Created by: Dima Ruban <dima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	llnlxftp
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	https://computing.llnl.gov/resources/xdir/
DISTNAME=	llnlxftp2.1
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif FTP client

PLIST_FILES=	bin/xftp lib/X11/app-defaults/XFtp
WRKSRC=		${WRKDIR}/llnlxftp2.1/sources
USES=		imake motif
USE_XORG=	ice sm x11 xext xp xt

CFLAGS+=	-Wno-implicit-int \
		-Wno-implicit-function-declaration \
		-Wno-return-type

MAN1=		xftp.1

.include <bsd.port.mk>
