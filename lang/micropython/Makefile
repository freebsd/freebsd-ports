# $FreeBSD$

PORTNAME=	micropython
PORTVERSION=	1.5.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	lang python

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Implementation of the Python language for microcontrollers

LICENSE=	MIT

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		gmake pkgconfig python:3,build readline shebangfix

USE_GITHUB=	yes

PLIST_FILES=	bin/micropython

WRKSRC_SUBDIR=	unix

SHEBANG_FILES=	../tools/make-frozen.py
MAKE_ARGS+=	V=1
MAKE_ENV+=	PYTHON=${PYTHON_CMD} CFLAGS_EXTRA="${CPPFLAGS} ${CFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
# Our default GCC 4.2.1 build can't handle some quirks correctly.
# Use an up to date version for FreeBSD releases, which use GCC
# as default compiler
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||;/^COPT =/d; \
		s|ls -1 -v|ls -1|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|re_exec|mp_re_exec|' \
		${WRKSRC}/../extmod/modure.c
	@${REINPLACE_CMD} -e 's|AS =|AS ?=|;s|LD =|LD ?=|; \
		s|CC =|CC ?=|;s|PYTHON =|PYTHON ?=|' \
		${WRKSRC}/../py/mkenv.mk
	@${REINPLACE_CMD} -e 's|libc\.so\.6|libc\.so\.7|;' \
		${WRKSRC}/../tests/unix/ffi_callback.py \
		${WRKSRC}/../tests/unix/ffi_float.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micropython ${STAGEDIR}${PREFIX}/bin

regression-test: build
	${RM} ${WRKSRC}/../tests/basics/memoryerror.py
	cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.post.mk>
