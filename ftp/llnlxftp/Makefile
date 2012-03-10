# New ports collection makefile for:	llnlxftp
# Date created:				9 November 1997
# Whom: Dima Ruban <dima@FreeBSD.org>
#
# $FreeBSD$
#

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
USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xp xt

MAN1=		xftp.1

.include <bsd.port.mk>
