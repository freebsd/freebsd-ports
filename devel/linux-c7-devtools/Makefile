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

BUVERSION=	2.27-44.base.el7
BIN_DISTNAMES=	binutils-${BUVERSION} \
		glibc-headers-2.17-323.el7_9 \
		mpfr-3.1.1-4.el7 \
		cpp-4.8.5-44.el7 \
		gcc-4.8.5-44.el7 \
		gcc-c++-4.8.5-44.el7 \
		gcc-gfortran-4.8.5-44.el7 \
		libstdc++-devel-4.8.5-44.el7
LIB_DISTNAMES=	binutils-devel-${BUVERSION} \
		glibc-devel-2.17-323.el7_9 \
		glibc-static-2.17-323.el7_9 \
		libgomp-4.8.5-44.el7 \
		libmpc-1.0.1-3.el7
DISTFILES_amd64=${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
		${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
		${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
		kernel-headers-3.10.0-1160.15.2.el7${EXTRACT_SUFX_amd64}:amd64
DISTFILES_i386=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
		${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:i386/} \
		kernel-headers-3.10.0-1160.15.2.el7.centos.plus${EXTRACT_SUFX_i386}:i386
SRC_DISTFILES=	binutils-${BUVERSION}${SRC_SUFX}:SOURCE \
		glibc-2.17-323.el7_9${SRC_SUFX}:SOURCE \
		kernel-3.10.0-1160.15.2.el7${SRC_SUFX}:SOURCE \
		libmpc-1.0.1-3.el7${SRC_SUFX}:SOURCE \
		mpfr-3.1.1-4.el7${SRC_SUFX}:SOURCE \
		gcc-4.8.5-44.el7${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

PLIST_SUB=	BUVERSION=${BUVERSION}

.include <bsd.port.options.mk>

post-install:
	${LN} -sf ld.bfd ${STAGEDIR}${PREFIX}/usr/bin/ld
.if ${ARCH} == amd64
	${LN} -sfh ../../../../lib64/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.8.2/libgcc_s.so

	${LN} -sfh ../../../../libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/x86_64-redhat-linux/4.8.2/32/libgcc_s.so
.else
	${LN} -sfh ../../../libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/i686-redhat-linux/4.8.2/libgcc_s.so
.endif

.include <bsd.port.mk>
