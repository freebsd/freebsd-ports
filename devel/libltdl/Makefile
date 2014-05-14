# Created by: Jeremy Norris <ishmael27x@yahoo.com>
# $FreeBSD$

PORTNAME=	libltdl
MASTERDIR=	${.CURDIR}/../../devel/libtool

COMMENT=	System independent dlopen wrapper

LICENSE=	LGPL21
USE_LDCONFIG=	yes
USES=		libtool:keepla
CONFIGURE_ARGS=	--enable-ltdl-install

CONFIGURE_WRKSRC=${WRKSRC}/libltdl
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
INFO=		# empty
INSTALL_TARGET=	install-strip

.include "${MASTERDIR}/Makefile"
