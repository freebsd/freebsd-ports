# New ports collection makefile for:	magicpoint (with vflib)
# Version required:	1.04a
# Date created:		25 Dec 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.6 1998/12/01 03:06:05 asami Exp $
#

MASTERDIR=	${.CURDIR}/../../misc/magicpoint
COMMENT=	${.CURDIR}/pkg/COMMENT

LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib

PKGNAME=	ja-magicpoint-1.04a

.include "${MASTERDIR}/Makefile"

CATEGORIES=	japanese misc

MAINTAINER=	itojun@itojun.org

# dirty, but this is required for version independent-ness
CONFIGURE_ARGS=	--with-vfontcap=`echo ${LOCALBASE}/share/VFlib/*/vfontcap | tail -1`
