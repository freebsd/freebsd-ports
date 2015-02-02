# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	6.6
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	CENTOS_LINUX CENTOS_LINUX_UPDATES
DISTFILES=	binutils-2.20.51.0.2-5.42.el6.i686.rpm \
		binutils-devel-2.20.51.0.2-5.42.el6.i686.rpm \
		glibc-devel-2.12-1.149.el6_6.5.i686.rpm \
		glibc-headers-2.12-1.149.el6_6.5.i686.rpm \
		kernel-headers-2.6.32-504.8.1.el6.i686.rpm \
		libstdc++-devel-4.4.7-11.el6.i686.rpm \
		libgomp-4.4.7-11.el6.i686.rpm \
		mpfr-2.4.1-6.el6.i686.rpm \
		cpp-4.4.7-11.el6.i686.rpm \
		gcc-4.4.7-11.el6.i686.rpm \
		gcc-c++-4.4.7-11.el6.i686.rpm \
		gcc-gfortran-4.4.7-11.el6.i686.rpm

MAINTAINER=	emulation@freebsd.org
COMMENT=	Linux compilers and base libraries (CentOS ${LINUX_DIST_VER})

# LICENSE=	Various GNU

RUN_DEPENDS+=	linux-c6-libgfortran>0:${PORTSDIR}/devel/linux-c6-libgfortran

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

PLIST_SUB+=	NLS=""

SRC_DISTFILES=	binutils-2.20.51.0.2-5.42.el6.src.rpm \
		glibc-2.12-1.149.el6_6.5.src.rpm \
		kernel-2.6.32-504.8.1.el6.src.rpm \
		mpfr-2.4.1-6.el6.src.rpm \
		gcc-4.4.7-11.el6.src.rpm

post-install:
	${LN} -sf ${LINUXBASE}/lib/libgcc_s.so.1 \
	${STAGEDIR}${PREFIX}/usr/lib/gcc/i686-redhat-linux/4.4.4/libgcc_s.so

.include <bsd.port.mk>
