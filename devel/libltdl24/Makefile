# New ports collection makefile for:	libltdl
# Date created:		23 January 2002
# Whom:			Jeremy Norris <ishmael27x@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	libltdl
MASTERDIR=	${.CURDIR}/../../devel/libtool24

COMMENT=	System independent dlopen wrapper

LICENSE=	LGPL21
LICENSE_FILE=	${CONFIGURE_WRKSRC}/COPYING.LIB
USE_GNOME=	ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:24
LIBTOOLFILES=	libltdl/configure
CONFIGURE_ARGS=	--enable-ltdl-install

CONFIGURE_WRKSRC=${WRKSRC}/libltdl
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
LATEST_LINK=	libltdl24
INFO=		# empty

.include "${MASTERDIR}/Makefile"
