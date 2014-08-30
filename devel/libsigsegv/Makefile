# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	libsigsegv
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU/libsigsegv

MAINTAINER=	gaod@hychen.org
COMMENT=	Handling page faults in user mode

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	AWK="${AWK}" --enable-shared
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

PLIST_FILES=	include/sigsegv.h \
		lib/libsigsegv.a \
		lib/libsigsegv.so \
		lib/libsigsegv.so.2 \
		lib/libsigsegv.so.2.0.3

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
