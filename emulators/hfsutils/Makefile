# New ports collection makefile for:	hfsutils
# Version required:	3.2
# Date Created:		7 Sep 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.9 1998/03/21 19:19:42 vanilla Exp $
#

DISTNAME=	hfsutils-3.2
CATEGORIES=	emulators tk81
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/ \
		http://www.freebsd.org/~vanilla/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	tk81\\.1\\.:${PORTSDIR}/x11-toolkits/tk81

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl --with-tcl-libs=${PREFIX}/lib --with-tk --with-tk-libs=${PREFIX}/lib

MAN1=		hattrib.1 hcd.1 hcopy.1 hdel.1 hdir.1 hformat.1 hfs.1 \
		hfssh.1 hfsutils.1 hls.1 hmkdir.1 hmount.1 hpwd.1 \
		hrename.1 hrmdir.1 humount.1 hvol.1 xhfs.1

post-install:
		chmod 755 ${PREFIX}/bin/hfs

.include <bsd.port.mk>
