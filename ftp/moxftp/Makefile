# New ports collection makefile for:	moxftp
# Version required:	2.2
# Date created:		19 December 1994
# Whom:			janek
#
# $Id$
#

DISTNAME=	moxftp-2.2
CATEGORIES+=	networking
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/
EXTRACT_SUFX=	.tar.Z

HAS_CONFIGURE=	yes
PREFIX=	/usr/X11R6

# CONFIGURE_ARGS set to :
#	motif - for motif version, (not tested!!!)
#	athena - for athena version,
#	athena3d - for athena 3 d version, (you should have installed Xaw3d!!!)
#	openlook - for open look version - (not tested!!!)
# If you use athena3d uncomment DEPENDS !!!
CONFIGURE_ARGS=	athena

#DEPENDS=	${PORTSDIR}/x11/Xaw3d

.include <bsd.port.mk>

install:
	@mkdir -p ${PREFIX}/man/man1
	@install -c -m 0444 ${WRKSRC}/xftp.man ${PREFIX}/man/man1/xftp.1
	@gzip -9n ${PREFIX}/man/man1/xftp.1
