# New ports collection makefile for:	hfsutils
# Version required:	2.0
# Date Created:		7 Sep 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.1.1.1 1997/11/14 13:53:06 tg Exp $
#

DISTNAME=	hfsutils-2.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.ps.ucl.ac.uk/pub/mkhfs/

MAINTAINER=	vanilla@@FreeBSD.ORG

LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11/tk80

MAKE_ENV+=	COPTS="${CFLAGS}"
MAN1=		hattrib.1 hcd.1 hcopy.1 hdel.1 hdir.1 hformat.1 hfs.1 \
		hfssh.1 hfsutils.1 hls.1 hmkdir.1 hmount.1 hpwd.1 \
		hrename.1 hrmdir.1 humount.1 hvol.1 xhfs.1

.include <bsd.port.mk>
