# Created by: nox@FreeBSD.org

PORTNAME=	linux_libusb
PORTVERSION=	13.1.0
CATEGORIES=	devel linux

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Linux-compatibility LibUSB

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		linux tar:bzip2

USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_LINUX=	base:build,run devtools:build
USE_LINUX_PREFIX=	yes

GH_ACCOUNT=	hselasky

LIBDIR_aarch64=	lib64
LIBDIR_amd64=	lib64
LIBDIR_i386=	lib
PLIST_FILES=	usr/${LIBDIR_${ARCH}}/libusb.so.3 \
		usr/${LIBDIR_${ARCH}}/libusb-0.1.so.4 \
		usr/${LIBDIR_${ARCH}}/libusb-1.0.so.0

CC=		${LINUXBASE}/usr/bin/gcc --sysroot=${LINUXBASE}
CFLAGS:=	${CFLAGS:N-march=*}
CFLAGS+=	-I${WRKDIR}/${DISTNAME}/include
SSP_CFLAGS?=	-fstack-protector # XXX -strong isn't supported by GCC < 4.9
MAKE_ARGS+=	LIBUSB_GLOBAL_INCLUDE_FILE=libusb_global_linux.h
MAKE_ARGS+=	WITHOUT_PROFILE=yes
MAKE_ARGS+=	WITHOUT_SSP=yes
MAKE_ARGS+=	WITHOUT_WERROR=yes
MAKE_ARGS+=	__MAKE_CONF=""
MAKE_ENV+=	LDADD="-lrt"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300134
MAKE_ARGS+=	NO_WERROR=yes
.endif

.if ${ARCH} == amd64
PLIST_FILES+=	usr/lib/libusb.so.3 \
		usr/lib/libusb-0.1.so.4 \
		usr/lib/libusb-1.0.so.0
.endif

do-build:
	${MKDIR} ${WRKSRC}/${LIBDIR_${ARCH}}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} MAKEOBJDIR=${LIBDIR_${ARCH}} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} \
		${MAKE_ARGS:N${DESTDIRNAME}=*}
.if ${ARCH} == amd64
	${MKDIR} ${WRKSRC}/lib
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV:NCC=*} CC="${CC} -m32" \
		MAKEOBJDIR=lib ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS:N${DESTDIRNAME}=*} COMPAT_32BIT=yes
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/${LIBDIR_${ARCH}}
	${INSTALL_LIB} ${WRKSRC}/${LIBDIR_${ARCH}}/libusb.so.3 \
		${STAGEDIR}${PREFIX}/usr/${LIBDIR_${ARCH}}
	${LN} -s libusb.so.3 \
		${STAGEDIR}${PREFIX}/usr/${LIBDIR_${ARCH}}/libusb-0.1.so.4
	${LN} -s libusb.so.3 \
		${STAGEDIR}${PREFIX}/usr/${LIBDIR_${ARCH}}/libusb-1.0.so.0
.if ${ARCH} == amd64
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libusb.so.3 \
		${STAGEDIR}${PREFIX}/usr/lib
	${LN} -s libusb.so.3 \
		${STAGEDIR}${PREFIX}/usr/lib/libusb-0.1.so.4
	${LN} -s libusb.so.3 \
		${STAGEDIR}${PREFIX}/usr/lib/libusb-1.0.so.0
.endif

.include <bsd.port.post.mk>
