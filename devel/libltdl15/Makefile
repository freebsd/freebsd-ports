# New ports collection makefile for:	libltdl
# Date created:		23 January 2002
# Whom:			Jeremy Norris <ishmael27x@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	libltdl
PORTREVISION=	0
MASTERDIR=	${.CURDIR}/../libtool14

COMMENT=	System independent dlopen wrapper

INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-ltdl-install
BUILD_WRKSRC=	${WRKSRC}/libltdl
INSTALL_WRKSRC=	${WRKSRC}/libltdl
DESCR=		${PKGDIR}/pkg-descr.libltdl
PLIST=		${PKGDIR}/pkg-plist.libltdl

.include "${MASTERDIR}/Makefile"
