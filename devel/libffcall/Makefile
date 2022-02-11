# Created by: jagapen@home.com

PORTNAME=	libffcall
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	ndowens04@gmail.com
COMMENT=	Foreign function call libraries

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=	fails to build: gmake[2]: No rule to make target 'avcall-mipsn32-macro.S', needed by 'avcall-mipsn32.s'
BROKEN_mips64=	fails to build: gmake[2]: No rule to make target 'avcall-mips64-macro.S', needed by 'avcall-mips64.s'

USES=		gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=		--enable-shared
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=		-fPIC

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
USES+=		compiler:gcc-c++11-lib
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libavcall.so \
		${STAGEDIR}${PREFIX}/lib/libcallback.so \
		${STAGEDIR}${PREFIX}/lib/libtrampoline.so

.include <bsd.port.mk>
