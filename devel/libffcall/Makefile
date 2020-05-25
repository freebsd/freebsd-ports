# Created by: jagapen@home.com
# $FreeBSD$

PORTNAME=	libffcall
PORTVERSION=	2.1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Foreign function call libraries

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to build: avcall-armhf.s:46:2: error: '.syntax divided' arm assembly not supported
BROKEN_armv7=		fails to build: avcall-armhf.s:46:2: error: '.syntax divided' arm assembly not supported
BROKEN_mips=		fails to build: gmake[2]: No rule to make target 'avcall-mipsn32-macro.S', needed by 'avcall-mipsn32.s'
BROKEN_mips64=		fails to build: gmake[2]: No rule to make target 'avcall-mips64-macro.S', needed by 'avcall-mips64.s'

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_LDCONFIG=	yes

CONFIGURE_ARGS=		--enable-shared
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=		-fPIC

PATCHES_powerpc64=	${PATCHDIR}/extra-patch-ffcall-abi.h
EXTRA_PATCHES=		${PATCHES_${ARCH}}
USES_powerpc64=		compiler:gcc-c++11-lib
USES+=			${USES_${ARCH}}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libavcall.so \
		${STAGEDIR}${PREFIX}/lib/libcallback.so \
		${STAGEDIR}${PREFIX}/lib/libtrampoline.so

.include <bsd.port.mk>
