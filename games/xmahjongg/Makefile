# New ports collection makefile for:	xmahjongg
# Version required:	
# Date created:		16 Aug 1996
# Whom:			joerg@freebsd.org
#
# $Id: Makefile,v 1.3 1996/12/08 01:11:27 max Exp $
#

DISTNAME=	xmahjongg
PKGNAME=	xmahjongg-1.0
CATEGORIES=	games
# Most Usenet archive sites don't store it as a .tar.gz, but Slackware
# and it's mirrors do.
MASTER_SITES=	ftp://wcarchive.cdrom.com/pub/linux/slackware/source/xap/xgames/

MAINTAINER=	joerg@freebsd.org

WRKSRC=		${WRKDIR}/xmahjongg
USE_IMAKE=	yes
MAN6=		xmahjongg.6

NO_CDROM=	"Restrictive copyright"

post-extract:
	@${CP} ${WRKSRC}/xmahjongg.6 ${WRKSRC}/xmahjongg.man

.include <bsd.port.mk>
