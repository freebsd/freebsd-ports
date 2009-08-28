# New ports collection makefile for:	llnlxftp
# Date created:				9 November 1997
# Whom: Dima Ruban <dima@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	llnlxftp
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.llnl.gov/pub/ia/llnlxftp/
DISTNAME=	latest_xftp
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif FTP client

PLIST_FILES=	bin/xftp lib/X11/app-defaults/XFtp
WRKSRC=		${WRKDIR}/llnlxftp2.1/sources
USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xp xt

MAN1=		xftp.1

.include <bsd.port.mk>
