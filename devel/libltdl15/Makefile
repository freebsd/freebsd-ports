# New ports collection makefile for:	libltdl
# Date created:		23 January 2002
# Whom:			Jeremy Norris <ishmael27x@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	libltdl
PORTREVISION=	0
MASTERDIR=	${.CURDIR}/../libtool15

COMMENT=	System independent dlopen wrapper

INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-ltdl-install
BUILD_WRKSRC=	${WRKSRC}/libltdl
INSTALL_WRKSRC=	${WRKSRC}/libltdl
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
LATEST_LINK=	libltdl15

.include "${MASTERDIR}/Makefile"
