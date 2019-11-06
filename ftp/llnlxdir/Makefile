# Created by: Dima Ruban <dima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	llnlxdir
PORTVERSION=	2.1.2
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	https://computing.llnl.gov/resources/xdir/
DISTNAME=	llnlxdir2_1_2

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif FTP client with drag-and-drop file transfer

BROKEN=		unfetchable

PLIST_FILES=	bin/xdir lib/X11/app-defaults/XDir man/man1/xdir.1.gz

WRKSRC=		${WRKDIR}/llnlxdir2_1_2/sources
USES=		imake motif tar:Z xorg
USE_XORG=	ice sm x11 xext xt

.include <bsd.port.mk>
