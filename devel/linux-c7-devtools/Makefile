# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	2
CATEGORIES=	devel
BIN_DISTFILES=	binutils-2.23.52.0.1-55.el7${EXTRACT_SUFX} \
		glibc-headers-2.17-105.el7${EXTRACT_SUFX} \
		kernel-headers-3.10.0-327.36.3.el7${EXTRACT_SUFX} \
		mpfr-3.1.1-4.el7${EXTRACT_SUFX} \
		cpp-4.8.5-4.el7${EXTRACT_SUFX} \
		gcc-4.8.5-4.el7${EXTRACT_SUFX} \
		gcc-c++-4.8.5-4.el7${EXTRACT_SUFX} \
		gcc-gfortran-4.8.5-4.el7${EXTRACT_SUFX}
LIB_DISTFILES=	binutils-devel-2.23.52.0.1-55.el7${EXTRACT_SUFX} \
		glibc-devel-2.17-105.el7${EXTRACT_SUFX} \
		libstdc++-devel-4.8.5-4.el7${EXTRACT_SUFX} \
		libgomp-4.8.5-4.el7${EXTRACT_SUFX} \
		libmpc-1.0.1-3.el7${EXTRACT_SUFX}
SRC_DISTFILES=	binutils-2.23.52.0.1-55.el7${SRC_SUFX}:SOURCE \
		glibc-2.17-105.el7${SRC_SUFX}:SOURCE \
		kernel-3.10.0-327.36.3.el7${SRC_SUFX}:SOURCE \
		libmpc-1.0.1-3.el7${SRC_SUFX}:SOURCE \
		mpfr-3.1.1-4.el7${SRC_SUFX}:SOURCE \
		gcc-4.8.5-4.el7${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux compilers and base libraries (CentOS ${LINUX_DIST_VER})

CONFLICT=	linux-c6-${PORTNAME}-[0-9]*

# LICENSE=	Various GNU

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libgfortran
USE_LINUX_RPM=	yes

.include <bsd.port.pre.mk>

post-install:
.if ${LINUX_ARCH} == x86_64
	${LN} -sf ${LINUXBASE}/usr/lib64/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.8.2/libgcc_s.so

	${LN} -sf ${LINUXBASE}/usr/lib/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.8.2/32/libgcc_s.so
.else
	${LN} -sf ${LINUXBASE}/usr/lib/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/i686-redhat-linux/4.8.2/libgcc_s.so
.endif

.include <bsd.port.post.mk>
