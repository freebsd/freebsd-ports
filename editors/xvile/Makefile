# New ports collection makefile for:    xvile
# Version required:     7.3
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $Id: Makefile,v 1.13 1997/09/06 19:58:03 gj Exp $
#

DISTNAME=	vile-7.3
PKGNAME=	xvile-7.3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gj@freebsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-screen=${SCREEN_TYPE}
MAN1=		xvile.1
NO_PATCH=	yes

pre-configure:
	@echo "To use xvile with menus, set the environment variable USE_MENUS"

.if defined(USE_MENUS)
SCREEN_TYPE=	Xaw
.else
SCREEN_TYPE=	x11
.endif

post-install:
	@echo "You might want to copy the *.rc files from the source tree before"
	@echo "doing \`make clean'."
.if defined(USE_MENUS)
	@echo "And also take a look at README.MENU !"
.endif

.include <bsd.port.mk>
