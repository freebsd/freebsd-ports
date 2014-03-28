# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/${PORTVERSION}/${LINUX_RPM_ARCH}/:bin \
		http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/${PORTVERSION}/Fedora/${LINUX_RPM_ARCH}/os/Packages/:bin
PKGNAMEPREFIX=	linux-f10-
DISTFILES=	binutils-2.18.50.0.9-8.fc10.${LINUX_RPM_ARCH}.rpm:bin \
		binutils-devel-2.18.50.0.9-8.fc10.${LINUX_RPM_ARCH}.rpm:bin \
		glibc-devel-2.9-3.${LINUX_RPM_ARCH}.rpm:bin \
		glibc-headers-2.9-3.${LINUX_RPM_ARCH}.rpm:bin \
		gmp-4.2.2-8.fc10.${LINUX_RPM_ARCH}.rpm:bin \
		kernel-headers-2.6.27.41-170.2.117.fc10.${LINUX_RPM_ARCH}.rpm:bin \
		mpfr-2.3.2-1.fc10.${LINUX_RPM_ARCH}.rpm:bin \
		cpp-4.3.2-7.${LINUX_RPM_ARCH}.rpm:bin \
		gcc-4.3.2-7.${LINUX_RPM_ARCH}.rpm:bin \
		gcc-c++-4.3.2-7.${LINUX_RPM_ARCH}.rpm:bin \
		gcc-gfortran-4.3.2-7.${LINUX_RPM_ARCH}.rpm:bin

.if defined(PACKAGE_BUILDING)
MASTER_SITES+=	http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/${PORTVERSION}/SRPMS/:src \
		http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/${PORTVERSION}/Fedora/source/SRPMS/:src
SRC_DISTFILES=	binutils-2.18.50.0.9-8.fc10.src.rpm:src \
		glibc-2.9-3.src.rpm:src \
		gmp-4.2.2-8.fc10.src.rpm:src \
		kernel-2.6.27.5-117.fc10.src.rpm:src \
		mpfr-2.3.2-1.fc10.src.rpm:src \
		gcc-4.3.2-7.src.rpm:src
.endif

MAINTAINER=	jwbacon@tds.net
COMMENT=	Linux compilers and base libraries

# LICENSE=	Various GNU

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
USE_LDCONFIG=	yes

PLIST_SUB+=	NLS=""

# Replace link to absolute path /lib/libgcc_s.so.1, which is a FreeBSD lib
post-install:
	${RM} ${STAGEDIR}/compat/linux/usr/lib/gcc/i386-redhat-linux/4.3.2/libgcc_s.so
	${LN} -s ../../../../../lib/libgcc_s.so.1 ${STAGEDIR}/compat/linux/usr/lib/gcc/i386-redhat-linux/4.3.2/libgcc_s.so

.include <bsd.port.mk>
