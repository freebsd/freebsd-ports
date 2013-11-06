# Created by: ijliao
# $FreeBSD$

PORTNAME=	lightning
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates assembly language code at run-time

OPTIONS_DEFINE=	ASSERTIONS
ASSERTIONS_DESC=Enable runtime code generation assertions

ASSERTIONS_CONFIGURE_ON=--enable-assertions=yes
ASSERTIONS_CONFIGURE_OFF=--enable-assertions=no

ONLY_FOR_ARCHS=	i386 amd64 arm ia64 powerpc sparc64 mips

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-disassembler=no

PLIST_SUB+=	JIT_ARCH=${ARCH:S/i386/x86/:S/amd64/x86/:S/x86_64/x86/:S/sparc64/sparc/:S/powerpc/ppc/}

regression-test: build
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
