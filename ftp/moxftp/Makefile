# New ports collection makefile for:	moxftp
# Version required:	2.2
# Date created:		19 December 1994
# Whom:			janek
#
# $Id: Makefile,v 1.6 1995/04/22 12:30:11 asami Exp $
#

DISTNAME=	moxftp-2.2
CATEGORIES+=	networking
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/
EXTRACT_SUFX=	.tar.Z

HAS_CONFIGURE=	yes
USE_X11=	yes
STRIP=

# CONFIGURE_ARGS set to :
#	motif - for motif version, (not tested!!!)
#	athena - for athena version,
#	athena3d - for athena 3 d version, (you should have installed Xaw3d!!!)
#	openlook - for open look version - (not tested!!!)
# If you use athena3d uncomment DEPENDS !!!
CONFIGURE_ARGS=	athena

#DEPENDS=	${PORTSDIR}/x11/Xaw3d

post-install:
	strip ${PREFIX}/bin/xftp
	install -c -m 0444 ${WRKSRC}/xftp.man ${PREFIX}/man/man1/xftp.1
	gzip -9nf ${PREFIX}/man/man1/xftp.1

.include <bsd.port.mk>
