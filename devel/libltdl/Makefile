# Created by: Jeremy Norris <ishmael27x@yahoo.com>
# $FreeBSD$

PORTNAME=	libltdl
MASTERDIR=	${.CURDIR}/../../devel/libtool

COMMENT=	System independent dlopen wrapper

LICENSE=	LGPL21
CONFIGURE_ENV=	LTVERHACK=1
MAKE_ENV=	LTVERHACK=1
USE_GNOME=	ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	libltdl/configure
CONFIGURE_ARGS=	--enable-ltdl-install

CONFIGURE_WRKSRC=${WRKSRC}/libltdl
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
INFO=		# empty

.include "${MASTERDIR}/Makefile"
