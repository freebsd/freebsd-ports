# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	devtools
PORTVERSION=	10
PORTREVISION=	2
CATEGORIES=	devel
BIN_DISTFILES=	binutils-2.18.50.0.9-8.fc10${EXTRACT_SUFX} \
		binutils-devel-2.18.50.0.9-8.fc10${EXTRACT_SUFX} \
		glibc-devel-2.9-3${EXTRACT_SUFX} \
		glibc-headers-2.9-3${EXTRACT_SUFX} \
		kernel-headers-2.6.27.41-170.2.117.fc10${EXTRACT_SUFX} \
		mpfr-2.3.2-1.fc10${EXTRACT_SUFX} \
		cpp-4.3.2-7${EXTRACT_SUFX} \
		gcc-4.3.2-7${EXTRACT_SUFX} \
		gcc-c++-4.3.2-7${EXTRACT_SUFX} \
		gcc-gfortran-4.3.2-7${EXTRACT_SUFX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Linux compilers and base libraries

SRC_DISTFILES=	binutils-2.18.50.0.9-8.fc10.src.rpm:SOURCE \
		glibc-2.9-3.src.rpm:SOURCE \
		kernel-2.6.27.5-117.fc10.src.rpm:SOURCE \
		mpfr-2.3.2-1.fc10.src.rpm:SOURCE \
		gcc-4.3.2-7.src.rpm:SOURCE

# LICENSE=	Various GNU

USES=		linux:f10
USE_LINUX_RPM=	nolib
USE_LDCONFIG=	yes

PLIST_SUB+=	NLS=""

# Replace link to absolute path /lib/libgcc_s.so.1, which is a FreeBSD lib
post-install:
	${RM} ${STAGEDIR}/compat/linux/usr/lib/gcc/i386-redhat-linux/4.3.2/libgcc_s.so
	${LN} -s ../../../../../lib/libgcc_s.so.1 ${STAGEDIR}/compat/linux/usr/lib/gcc/i386-redhat-linux/4.3.2/libgcc_s.so

.include <bsd.port.mk>
