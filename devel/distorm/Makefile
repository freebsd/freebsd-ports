PORTNAME?=	distorm
DISTVERSION=	20121220-r230
PORTREVISION?=	2
CATEGORIES=	devel
MASTER_SITES=	LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Fast x86 and x86-64 disassembler library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix tar:xz
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/make/linux

PLIST_FILES=	bin/disasm \
		include/distorm.h \
		include/mnemonics.h \
		lib/libdistorm3.a \
		lib/libdistorm3.so \
		lib/libdistorm3.so.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

do-build:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		EXTRAFLAGS="${PICFLAG} -DDISTORM_DYNAMIC" ${MAKE} ${_MAKE_JOBS} \
		${MAKE_ARGS} clib)
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		EXTRAFLAGS="-DDISTORM_STATIC" ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} staticlib)
	${CC} ${CFLAGS} ${LDFLAGS} -o ${BUILD_WRKSRC}/disasm \
		${WRKSRC}/examples/linux/main.c ${BUILD_WRKSRC}/libdistorm3.a

do-test:
	@cd ${BUILD_WRKSRC} && ./disasm disasm

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/libdistorm3.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${BUILD_WRKSRC}/libdistorm3.so ${STAGEDIR}${PREFIX}/lib/libdistorm3.so.1
	${LN} -sf libdistorm3.so.1 ${STAGEDIR}${PREFIX}/lib/libdistorm3.so
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/disasm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.post.mk>
