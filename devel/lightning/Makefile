# Created by: ijliao
# $FreeBSD$

PORTNAME=	lightning
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generates assembly language code at run-time

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

USES=		libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-disassembler=no
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	JIT_ARCH=${ARCH:S/i386/x86/:S/amd64/x86/:S/x86_64/x86/:S/sparc64/sparc/:S/powerpc/ppc/}

ONLY_FOR_ARCHS=	i386 amd64 arm ia64 powerpc sparc64 mips

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
