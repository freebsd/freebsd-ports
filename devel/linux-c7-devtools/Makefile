# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	${LINUX_DIST_VER}
CATEGORIES=	devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux compilers and base libraries (CentOS ${LINUX_DIST_VER})

# LICENSE=	Various GNU

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libgfortran
USE_LINUX_RPM=	yes

BIN_DISTNAMES=	binutils-2.27-34.base.el7 \
		glibc-headers-2.17-260.el7_6.5 \
		mpfr-3.1.1-4.el7 \
		cpp-4.8.5-36.el7_6.2 \
		gcc-4.8.5-36.el7_6.2 \
		gcc-c++-4.8.5-36.el7_6.2 \
		gcc-gfortran-4.8.5-36.el7_6.2
LIB_DISTNAMES=	binutils-devel-2.27-34.base.el7 \
		glibc-devel-2.17-260.el7_6.5 \
		libstdc++-devel-4.8.5-36.el7_6.2 \
		libgomp-4.8.5-36.el7_6.2 \
		libmpc-1.0.1-3.el7
DISTFILES_amd64=${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
		${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
		${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
		kernel-headers-3.10.0-957.12.2.el7${EXTRACT_SUFX_amd64}:amd64
DISTFILES_i386=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
		${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:i386/} \
		kernel-headers-3.10.0-957.12.2.el7.centos.plus${EXTRACT_SUFX_i386}:i386
SRC_DISTFILES=	binutils-2.27-34.base.el7${SRC_SUFX}:SOURCE \
		glibc-2.17-260.el7_6.5${SRC_SUFX}:SOURCE \
		kernel-3.10.0-957.12.2.el7${SRC_SUFX}:SOURCE \
		libmpc-1.0.1-3.el7${SRC_SUFX}:SOURCE \
		mpfr-3.1.1-4.el7${SRC_SUFX}:SOURCE \
		gcc-4.8.5-36.el7_6.2${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

post-install:
	${LN} -sf ld.bfd ${STAGEDIR}${PREFIX}/usr/bin/ld
.if ${LINUX_ARCH} == x86_64
	${LN} -sfh ../../../../lib64/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.8.2/libgcc_s.so

	${LN} -sfh ../../../../libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.8.2/32/libgcc_s.so
.else
	${LN} -sfh ../../../libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/i686-redhat-linux/4.8.2/libgcc_s.so
.endif

.include <bsd.port.post.mk>
