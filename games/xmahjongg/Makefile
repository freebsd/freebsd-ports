# New ports collection makefile for:	xmahjongg
# Version required:	
# Date created:		16 Aug 1996
# Whom:			joerg@freebsd.org
#
# $FreeBSD$
#

DISTNAME=	xmahjongg
PKGNAME=	xmahjongg-1.0
CATEGORIES=	games
# Most Usenet archive sites don't store it as a .tar.gz, but Slackware
# and it's mirrors do.
MASTER_SITES=	ftp://ftp.digex.net/pub/os/linux/slackware/source/xap/xgames/ \
		ftp://wcarchive.cdrom.com/pub/linux/slackware/source/xap/xgames/

MAINTAINER=	joerg@freebsd.org

WRKSRC=		${WRKDIR}/xmahjongg
USE_IMAKE=	yes
MAN6=		xmahjongg.6

NO_CDROM=	"Restrictive copyright"

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${WRKSRC}/xmahjongg.6 ${WRKSRC}/xmahjongg.man

pre-install:
.if !exists(${X11BASE}/lib/X11/fonts/local)
	@${ECHO} "*********************************************************"
	@${ECHO} "Please update your XFree86 to version 3.3.3 or later"
	@${ECHO} "or add ${X11BASE}/lib/X11/fonts/local to your font path"
	@${ECHO} "in /etc/XF86Config."
	@${ECHO} "*********************************************************"
.endif

.include <bsd.port.post.mk>
