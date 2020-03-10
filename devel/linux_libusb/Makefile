# Created by: nox@FreeBSD.org
# $FreeBSD$

PORTNAME=	linux_libusb
PORTVERSION=	13.0r${FSVN_REV}
CATEGORIES=	devel linux
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux-compatibility libusb

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386
USES=		linux tar:bzip2
USE_LDCONFIG=	yes
USE_LINUX=	devtools:build
USE_LINUX_PREFIX=	yes
PLIST_FILES=		usr/lib/libusb.so	\
			usr/lib/libusb.so.3	\
			usr/lib/libusb-0.1.so.4
CC=		${LINUXBASE}/usr/bin/gcc
CFLAGS+=	-I${WRKDIR}/${DISTNAME}/include
SSP_CFLAGS?=	-fstack-protector # XXX -strong isn't supported by GCC < 4.9
MAKE_ARGS+=	LIBUSB_GLOBAL_INCLUDE_FILE=libusb_global_linux.h
MAKE_ARGS+=	PTHREAD_LIBS="-lpthread -lrt"
MAKE_ARGS+=	NO_WERROR=yes
MAKE_ARGS+=	WITHOUT_PROFILE=yes
MAKE_ARGS+=	WITHOUT_SSP=yes
MAKE_ARGS+=	__MAKE_CONF=""

# see: sysutils/pc-sysinstall/Makefile
FSVN_REV=	358841
FSVNPATH?=	http://svn.freebsd.org/base/head
FSVNDIR=	lib/libusb

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAKE_ARGS+=	COMPAT_32BIT=YES
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/lib
	${INSTALL_LIB} ${WRKSRC}/libusb.so.3 ${STAGEDIR}${PREFIX}/usr/lib
	${LN} -s libusb.so.3 ${STAGEDIR}${PREFIX}/usr/lib/libusb.so
# Xilinx ISE requirement.
	${LN} -s libusb.so.3 ${STAGEDIR}${PREFIX}/usr/lib/libusb-0.1.so.4

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
SVN?=		svnlite

do-fetch:
	${RM} -rf ${WRKDIR}
	${MKDIR} ${WRKDIR}
	${SVN} export -r ${FSVN_REV} ${FSVNPATH}/${FSVNDIR} ${WRKDIR}/${DISTNAME}
	${MKDIR} ${WRKDIR}/${DISTNAME}/include/compat/linux
	${SVN} export -r ${FSVN_REV} ${FSVNPATH}/sys/compat/linux/linux_ioctl.h ${WRKDIR}/${DISTNAME}/include/compat/linux/
	${MKDIR} ${WRKDIR}/${DISTNAME}/include/dev/usb
	${SVN} export -r ${FSVN_REV} ${FSVNPATH}/sys/dev/usb/usb_endian.h ${WRKDIR}/${DISTNAME}/include/dev/usb/
	${SVN} export -r ${FSVN_REV} ${FSVNPATH}/sys/dev/usb/usb_freebsd.h ${WRKDIR}/${DISTNAME}/include/dev/usb/
	${SVN} export -r ${FSVN_REV} ${FSVNPATH}/sys/dev/usb/usb.h ${WRKDIR}/${DISTNAME}/include/dev/usb/
	${SVN} export -r ${FSVN_REV} ${FSVNPATH}/sys/dev/usb/usbdi.h ${WRKDIR}/${DISTNAME}/include/dev/usb/
	${SVN} export -r ${FSVN_REV} ${FSVNPATH}/sys/dev/usb/usb_ioctl.h ${WRKDIR}/${DISTNAME}/include/dev/usb/
	cd ${WRKDIR}; tar --uid=0 --gid=0 -cvyf ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.endif

.include <bsd.port.post.mk>
