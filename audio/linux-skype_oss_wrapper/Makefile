# Created by: Andriy Voskoboinyk <s3erios@gmail.com>
# $FreeBSD$

PORTNAME=	skype_oss_wrapper
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-

MAINTAINER=	s3erios@gmail.com
COMMENT=	Partial PulseAudio API implementation using OSS backend

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Only useful for net-im/skype4
EXPIRATION_DATE=	2019-04-30

USE_GITHUB=	yes
GH_ACCOUNT=	s3erios

MAKE_ARGS=	CC=${LINUXBASE}/usr/bin/gcc
USES=		linux
USE_LINUX=	base devtools:build
USE_LINUX_PREFIX=	yes
# do not define USE_LDCONFIG, it's not for global use
SSP_CFLAGS?=	-fstack-protector # XXX -strong isn't supported by GCC < 4.9

ONLY_FOR_ARCHS=	i386 amd64
PLIST_FILES=	lib/skype_oss_wrapper/libpulse.so.0

LIB_DIR=	${PREFIX}/lib/${PORTNAME}

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/skype_oss
	${RMDIR} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
