# New ports collection makefile for:	xmahjongg
# Version required:	
# Date created:		16 Aug 1996
# Whom:			joerg@freebsd.org
#
# $Id: Makefile,v 1.1.1.1 1996/08/27 20:16:32 joerg Exp $
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

NO_CDROM=	"Restrictive copyright."

post-extract:
	@cp ${WRKSRC}/xmahjongg.6 ${WRKSRC}/xmahjongg.man

.include <bsd.port.mk>
