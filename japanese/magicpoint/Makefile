# New ports collection makefile for:	magicpoint (with vflib)
# Version required:	1.04a
# Date created:		25 Dec 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.4 1998/09/06 13:48:20 itojun Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../misc/magicpoint/files
PATCHDIR=	${.CURDIR}/../../misc/magicpoint/patches
PKGDIR=		${.CURDIR}/../../misc/magicpoint/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

LIB_DEPENDS=	VFlib2.23:${PORTSDIR}/japanese/vflib

PKGNAME=	ja-magicpoint-1.04a

.include <${.CURDIR}/../../misc/magicpoint/Makefile>

CATEGORIES=	japanese misc

MAINTAINER=	itojun@itojun.org

# dirty, but this is required for version independent-ness
CONFIGURE_ARGS=	--with-vfontcap=`echo ${LOCALBASE}/share/VFlib/*/vfontcap | tail -1`
