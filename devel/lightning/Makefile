# Created by: ijliao
# $FreeBSD$

PORTNAME=	lightning
PORTVERSION=	2.1.2
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generates assembly language code at run-time

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64 arm armv6 armv7 i386 mips powerpc sparc64
BROKEN_armv6=	fails to link: ../lib/.libs/liblightning.so: undefined reference to `__addsf3'
BROKEN_armv7=	fails to link: ../lib/.libs/liblightning.so: undefined reference to `__addsf3'

USES=		libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-disassembler=no
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	JIT_ARCH=${ARCH:S/i386/x86/:S/amd64/x86/:S/x86_64/x86/:S/sparc64/sparc/:S/powerpc/ppc/}

INFO=		lightning

OPTIONS_DEFINE=	ASSERTIONS

ASSERTIONS_DESC=Enable runtime code generation assertions
ASSERTIONS_CONFIGURE_ON=--enable-assertions=yes
ASSERTIONS_CONFIGURE_OFF=--enable-assertions=no

post-patch:
	@${REINPLACE_CMD} -e \
		's|"gcc -E|"${CC:T} -E|' ${WRKSRC}/check/lightning.c

regression-test: build
	(cd ${BUILD_WRKSRC} &&  ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
