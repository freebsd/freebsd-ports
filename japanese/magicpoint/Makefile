# New ports collection makefile for:	magicpoint (with vflib)
# Version required:	1.05a
# Date created:		25 Dec 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.7 1998/12/23 01:31:37 steve Exp $
#

MASTERDIR=	${.CURDIR}/../../misc/magicpoint
COMMENT=	${.CURDIR}/pkg/COMMENT

LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib

PKGNAME=	ja-magicpoint-1.05a

.include "${MASTERDIR}/Makefile"

CATEGORIES=	japanese misc

MAINTAINER=	itojun@itojun.org

# dirty, but this is required for version independent-ness
CONFIGURE_ARGS+=	--with-vfontcap=`echo ${LOCALBASE}/share/VFlib/*/vfontcap | tail -1`
CONFIGURE_ARGS+=	--enable-freetype-charset16
