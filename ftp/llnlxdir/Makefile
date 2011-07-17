# New ports collection makefile for:	llnlxdir
# Date created:				9 November 1997
# Whom: Dima Ruban <dima@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	llnlxdir
PORTVERSION=	2.1.2
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	https://computing.llnl.gov/resources/xdir/
DISTNAME=	llnlxdir2_1_2
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif FTP client with drag-and-drop file transfer

PLIST_FILES=	bin/xdir lib/X11/app-defaults/XDir
MAN1=		xdir.1

WRKSRC=		${WRKDIR}/llnlxdir2_1_2/sources
USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xp xt

.include <bsd.port.mk>
