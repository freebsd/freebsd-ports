# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	7
CATEGORIES=	devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux compilers and base libraries (CentOS ${LINUX_DIST_VER})

# LICENSE=	Various GNU

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	libgfortran
USE_LINUX_RPM=	yes

BIN_DISTNAMES=	binutils-2.20.51.0.2-5.48.el6_10.1 \
		glibc-headers-2.12-1.212.el6_10.3 \
		kernel-headers-2.6.32-754.23.1.el6 \
		mpfr-2.4.1-6.el6 \
		cpp-4.4.7-23.el6 \
		gcc-4.4.7-23.el6 \
		gcc-c++-4.4.7-23.el6 \
		gcc-gfortran-4.4.7-23.el6 \
		libstdc++-devel-4.4.7-23.el6
LIB_DISTNAMES=	binutils-devel-2.20.51.0.2-5.48.el6_10.1 \
		glibc-devel-2.12-1.212.el6_10.3 \
		glibc-static-2.12-1.212.el6_10.3 \
		libgomp-4.4.7-23.el6
SRC_DISTFILES=	binutils-2.20.51.0.2-5.48.el6_10.1${SRC_SUFX}:SOURCE \
		glibc-2.12-1.212.el6_10.3${SRC_SUFX}:SOURCE \
		kernel-2.6.32-754.23.1.el6${SRC_SUFX}:SOURCE \
		mpfr-2.4.1-6.el6${SRC_SUFX}:SOURCE \
		gcc-4.4.7-23.el6${SRC_SUFX}:SOURCE

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-install:
.if ${ARCH} == amd64
	${LN} -sfh ../../../../lib64/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.4.4/libgcc_s.so

	${LN} -sfh ../../../../libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.4.4/32/libgcc_s.so
.else
	${LN} -sfh ../../../libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/i686-redhat-linux/4.4.4/libgcc_s.so
.endif

.include <bsd.port.mk>
