# New ports collection makefile for:	kinput2.canna+sj3
# Version required:	2.0p1
# Date created:		10 Aug 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $Id$
#

DISTNAME=	kinput2-v2-fix1
PKGNAME=	jp-cskinput2-2.0.1
CATEGORIES+=	japanese x11
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/

MAINTAINER=	hidekazu@cs.titech.ac.jp

BUILD_DEPENDS=	${LOCALBASE}/lib/libsj3lib.a:${PORTSDIR}/japanese/sj3
LIB_DEPENDS=	canna16\\.1\\.:${PORTSDIR}/japanese/Canna

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

.include <bsd.port.mk>
