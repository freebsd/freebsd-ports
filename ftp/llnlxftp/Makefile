# Created by: Dima Ruban <dima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	llnlxftp
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	ftp
MASTER_SITES=	https://computing.llnl.gov/resources/xdir/
DISTNAME=	llnlxftp2.1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif FTP client

BROKEN=		unfetchable

PLIST_FILES=	bin/xftp lib/X11/app-defaults/XFtp \
		man/man1/xftp.1.gz
WRKSRC=		${WRKDIR}/llnlxftp2.1/sources
USES=		imake motif tar:Z xorg
USE_XORG=	ice sm x11 xext xt

CFLAGS+=	-Wno-implicit-int \
		-Wno-implicit-function-declaration \
		-Wno-return-type

.include <bsd.port.mk>
