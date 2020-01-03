# Created by: nox@FreeBSD.org
# $FreeBSD$

PORTNAME=	linux_libusb
PORTVERSION=	11.0r${FSVN_REV}
PORTREVISION=	4
CATEGORIES=	devel linux
MASTER_SITES=	LOCAL/nox

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux-compatibility libusb

USES=		linux tar:bzip2
ONLY_FOR_ARCHS=	i386 amd64
USE_LDCONFIG=	yes
USE_LINUX=	devtools:build
USE_LINUX_PREFIX=	yes
PLIST_FILES=		usr/lib/libusb.so	\
			usr/lib/libusb.so.3	\
			usr/lib/libusb-0.1.so.4
CC=		${LINUXBASE}/usr/bin/gcc
CFLAGS+=	-I${WRKDIR}/sys
SSP_CFLAGS?=	-fstack-protector # XXX -strong isn't supported by GCC < 4.9
MAKE_ARGS+=	LIBUSB_GLOBAL_INCLUDE_FILE=libusb_global_linux.h
MAKE_ARGS+=	PTHREAD_LIBS="-lpthread -lrt"
MAKE_ARGS+=	NO_WERROR=yes
MAKE_ARGS+=	WITHOUT_PROFILE=yes
MAKE_ARGS+=	WITHOUT_SSP=yes
MAKE_ARGS+=	__MAKE_CONF=""
# XXX ${LINUXBASE}/usr/bin/ld is a broken link with gentoo atm?
#MAKE_ENV+=	COMPILER_PATH=/usr/i486-pc-linux-gnu/binutils-bin/2.22

# see: sysutils/pc-sysinstall/Makefile
FSVN_REV=	261448
FSVNPATH?=	http://svn.freebsd.org/base/head
FSVNDIR=	lib/libusb

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAKE_ARGS+=	COMPAT_32BIT=YES
.endif

pre-everything::
	@${ECHO_MSG} '===> Using the FreeBSD source tree under ${SRC_BASE}'
	@${ECHO_MSG} '===> Set SRC_BASE to use an alternate source tree'

.if !exists(${SRC_BASE}/sys/i386/linux/syscalls.master)
IGNORE=	requires kernel source present in ${SRC_BASE}/sys
.endif
#.if !exists(${SRC_BASE}/lib/libusb/Makefile)
#IGNORE=	requires libusb source present in ${SRC_BASE}/lib/libusb
#.endif
#.if exists(${LINUXBASE}/etc/fedora-release)
#IGNORE=	does not build with the default linux base, use the package instead
#.endif

post-patch:
	${MKDIR} ${WRKDIR}/sys
	${LN} -s ${SRC_BASE}/sys/compat ${SRC_BASE}/sys/dev ${WRKDIR}/sys

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/lib
	${INSTALL_LIB} ${WRKSRC}/libusb.so.3 ${STAGEDIR}${PREFIX}/usr/lib
	${LN} -s libusb.so.3 ${STAGEDIR}${PREFIX}/usr/lib/libusb.so
# Xilinx ISE requirement.
	${LN} -s libusb.so.3 ${STAGEDIR}${PREFIX}/usr/lib/libusb-0.1.so.4

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
#FETCH_DEPENDS+=		svn:devel/subversion
SVN?=		svnlite

do-fetch:
	${MKDIR} ${WRKDIR}
	${SVN} export -r ${FSVN_REV} ${FSVNPATH}/${FSVNDIR} ${WRKDIR}/${DISTNAME}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == noxNOTYET
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    nox@freefall.freebsd.org:public_distfiles/
.endif
.endif

.include <bsd.port.post.mk>
