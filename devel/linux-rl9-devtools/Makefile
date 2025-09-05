PORTNAME=	devtools
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux compilers and base libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://gcc.gnu.org/

# LICENSE=	Various GNU

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	elfutils-libs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

ONLY_FOR_ARCHS=	aarch64 amd64

QA_ENV+=		USESLIBTOOL=no

BUVERSION=	2.35.2-63.el9
GCCVERSION=	11.5.0-5.el9_5
GLIBCVERSION=	2.34-168.el9_6.23
KERNELVERSION=	5.14.0-570.37.1.el9_6
MPFRVERSION=	4.1.0-7.el9
LIBMPCVERSION=	1.2.1-4.el9

BIN_DISTNAMES=	binutils-${BUVERSION} \
		binutils-gold-${BUVERSION} \
		cpp-${GCCVERSION} \
		gcc-${GCCVERSION} \
		gcc-c++-${GCCVERSION} \
		gcc-gfortran-${GCCVERSION}
LIB_DISTNAMES=	binutils-devel-${BUVERSION} \
		glibc-devel-${GLIBCVERSION} \
		libatomic-${GCCVERSION} \
		libgfortran-${GCCVERSION} \
		libgomp-${GCCVERSION} \
		libmpc-${LIBMPCVERSION} \
		libstdc++-devel-${GCCVERSION}
LIB_DISTNAMES_aarch64=	k/kernel-headers-${KERNELVERSION}
LIB_DISTNAMES_amd64=	g/glibc-headers-${GLIBCVERSION} \
			k/kernel-headers-${KERNELVERSION}

SRC_DISTFILES=	binutils-${BUVERSION}${SRC_SUFX}:SOURCE \
		glibc-${GLIBCVERSION}${SRC_SUFX}:SOURCE \
		kernel-${KERNELVERSION}${SRC_SUFX}:SOURCE \
		libmpc-${LIBMPCVERSION}${SRC_SUFX}:SOURCE \
		gcc-${GCCVERSION}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME} \
		linux-rl9-libatomic

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

PLIST_SUB=	BUVERSION=${BUVERSION} \
		GGCVERSION=${GCCVERSION} \
		GLIBCVERSION=${GLIBCVERSION} \
		KERNELVERSION=${KERNELVERSION} \
		MPFRVERSION=${MPFRVERSION} \
		LIBMPCVERSION=${LIBMPCVERSION}

.include <bsd.port.options.mk>

post-install:
	${LN} -sf ld.bfd ${STAGEDIR}${PREFIX}/usr/bin/ld
.if ${ARCH} == aarch64
	${LN} -sfh ../../../../lib64/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/aarch64-redhat-linux/11/libgcc_s.so
.elif ${ARCH} == amd64
	${LN} -sfh ../../../../lib64/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/11/libgcc_s.so
	${LN} -sfh ../../../../libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/11/32/libgcc_s.so
.	if defined(WANT_LINUX32)
		${LN} -sfh ../../../libgcc_s.so.1 \
		${STAGEDIR}${PREFIX}/usr/lib/gcc/i686-redhat-linux/11/libgcc_s.so
.	endif
.endif

.include <bsd.port.mk>
