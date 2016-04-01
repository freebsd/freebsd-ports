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

BUILD_DEPENDS=	${LINUXBASE}/usr/bin/gcc:devel/linux-c6-devtools

USE_GITHUB=	yes
GH_ACCOUNT=	s3erios

USE_LINUX=	yes
USE_LINUX_PREFIX=	yes
# do not define USE_LDCONFIG, it's not for global use

ONLY_FOR_ARCHS=	i386 amd64
PLIST_FILES=	lib/skype_oss_wrapper/libpulse.so.0

LIB_DIR=	${PREFIX}/lib/${PORTNAME}

# hardcode compiler path
post-patch:
	@${REINPLACE_CMD} -e 's|?= cc| = ${LINUXBASE}/usr/bin/gcc|' \
			  -e 's|$${CC}|${LINUXBASE}/usr/bin/gcc|' \
		${WRKSRC}/Makefile

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/skype_oss
	@${RMDIR} ${STAGEDIR}${PREFIX}/bin
	@${BRANDELF} -t Linux ${STAGEDIR}${LIB_DIR}/libpulse.so.0

.include <bsd.port.mk>
