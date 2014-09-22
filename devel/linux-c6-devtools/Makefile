# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	6.5
CATEGORIES=	devel
DISTFILES=	binutils-2.20.51.0.2-5.36.el6.i686.rpm \
		binutils-devel-2.20.51.0.2-5.36.el6.i686.rpm \
		glibc-devel-2.12-1.132.el6.i686.rpm \
		glibc-headers-2.12-1.132.el6.i686.rpm \
		gmp-4.3.1-7.el6_2.2.i686.rpm \
		kernel-headers-2.6.32-431.el6.i686.rpm \
		mpfr-2.4.1-6.el6.i686.rpm \
		cpp-4.4.7-4.el6.i686.rpm \
		gcc-4.4.7-4.el6.i686.rpm \
		gcc-c++-4.4.7-4.el6.i686.rpm \
		gcc-gfortran-4.4.7-4.el6.i686.rpm

MAINTAINER=	emulation@freebsd.org
COMMENT=	Linux compilers and base libraries (CentOS ${LINUX_DIST_VER})

# LICENSE=	Various GNU

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

PLIST_SUB+=	NLS=""

SRC_DISTFILES=	binutils-2.20.51.0.2-5.36.el6.src.rpm \
		glibc-2.12-1.132.el6.src.rpm \
		gmp-4.3.1-7.el6_2.2.src.rpm \
		kernel-2.6.32-431.el6.src.rpm \
		mpfr-2.4.1-6.el6.src.rpm \
		gcc-4.4.7-4.el6.src.rpm

.include <bsd.port.mk>
