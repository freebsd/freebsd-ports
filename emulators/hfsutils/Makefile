# New ports collection makefile for:	hfsutils
# Date Created:		7 Sep 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	hfsutils
PORTVERSION=	3.2.6
PORTREVISION=	2
CATEGORIES=	emulators tk
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another HFS Utility

CONFLICTS=	hfs-[0-9]*

USE_TCL=	84
USE_TK=		84

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR}

MAN1=		hattrib.1 \
		hcd.1 \
		hcopy.1 \
		hdel.1 \
		hdir.1 \
		hformat.1 \
		hfs.1 \
		hfssh.1 \
		hfsutils.1 \
		hls.1 \
		hmkdir.1 \
		hmount.1 \
		hpwd.1 \
		hrename.1 \
		hrmdir.1 \
		humount.1 \
		hvol.1 \
		xhfs.1

post-install:
		${CHMOD} 755 ${PREFIX}/bin/hfs

.include <bsd.port.mk>
