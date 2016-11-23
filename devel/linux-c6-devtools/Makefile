# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	4
CATEGORIES=	devel
BIN_DISTFILES=	binutils-2.20.51.0.2-5.44.el6${EXTRACT_SUFX} \
		glibc-headers-2.12-1.192.el6${EXTRACT_SUFX} \
		kernel-headers-2.6.32-642.11.1.el6${EXTRACT_SUFX} \
		mpfr-2.4.1-6.el6${EXTRACT_SUFX} \
		cpp-4.4.7-17.el6${EXTRACT_SUFX} \
		gcc-4.4.7-17.el6${EXTRACT_SUFX} \
		gcc-c++-4.4.7-17.el6${EXTRACT_SUFX} \
		gcc-gfortran-4.4.7-17.el6${EXTRACT_SUFX}
LIB_DISTFILES=	binutils-devel-2.20.51.0.2-5.44.el6${EXTRACT_SUFX} \
		glibc-devel-2.12-1.192.el6${EXTRACT_SUFX} \
		libstdc++-devel-4.4.7-17.el6${EXTRACT_SUFX} \
		libgomp-4.4.7-17.el6${EXTRACT_SUFX}
SRC_DISTFILES=	binutils-2.20.51.0.2-5.44.el6${SRC_SUFX}:SOURCE \
		glibc-2.12-1.192.el6${SRC_SUFX}:SOURCE \
		kernel-2.6.32-642.11.1.el6${SRC_SUFX}:SOURCE \
		mpfr-2.4.1-6.el6${SRC_SUFX}:SOURCE \
		gcc-4.4.7-17.el6${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux compilers and base libraries (CentOS ${LINUX_DIST_VER})

# LICENSE=	Various GNU

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	libgfortran
USE_LINUX_RPM=	yes

.include <bsd.port.pre.mk>

post-install:
.if ${LINUX_ARCH} == x86_64
	${LN} -sf ${LINUXBASE}/lib64/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.4.4/libgcc_s.so

	${LN} -sf ${LINUXBASE}/lib/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.4.4/32/libgcc_s.so
.else
	${LN} -sf ${LINUXBASE}/lib/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/i686-redhat-linux/4.4.4/libgcc_s.so
.endif

.include <bsd.port.post.mk>
