# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=	dyncall
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.dyncall.org/r${PORTVERSION}/ \
		http://www.potion-studios.com/

MAINTAINER=	tphilipp@potion-studios.com
COMMENT=	Highly dynamic multi-platform foreign function call interface library

LICENSE=	ISCL

BROKEN_armv6=		fails to compile: unexpected token in operand
BROKEN_armv7=		fails to compile: unexpected token in operand

HAS_CONFIGURE=	yes

CFLAGS+=	-fPIC

# There is no install target in the BSD makefile for this version of the dyncall
# library, so install it manually.

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_DATA} \
		${WRKSRC}/dyncall/dyncall_value.h \
		${WRKSRC}/dyncall/dyncall_macros.h \
		${WRKSRC}/dyncall/dyncall_callf.h \
		${WRKSRC}/dyncall/dyncall_types.h \
		${WRKSRC}/dyncall/dyncall_signature.h \
		${WRKSRC}/dyncall/dyncall_config.h \
		${WRKSRC}/dyncall/dyncall.h \
		${WRKSRC}/dyncallback/dyncall_alloc_wx.h \
		${WRKSRC}/dyncallback/dyncall_thunk_x86.h \
		${WRKSRC}/dyncallback/dyncall_thunk_x64.h \
		${WRKSRC}/dyncallback/dyncall_thunk_sparc64.h \
		${WRKSRC}/dyncallback/dyncall_thunk_sparc32.h \
		${WRKSRC}/dyncallback/dyncall_thunk_mips.h \
		${WRKSRC}/dyncallback/dyncall_thunk_ppc64.h \
		${WRKSRC}/dyncallback/dyncall_thunk_ppc32.h \
		${WRKSRC}/dyncallback/dyncall_thunk_arm32_thumb.h \
		${WRKSRC}/dyncallback/dyncall_thunk_arm32_arm.h \
		${WRKSRC}/dyncallback/dyncall_thunk_arm64.h \
		${WRKSRC}/dyncallback/dyncall_thunk.h \
		${WRKSRC}/dyncallback/dyncall_callback_x86.h \
		${WRKSRC}/dyncallback/dyncall_callback_x64.h \
		${WRKSRC}/dyncallback/dyncall_callback_sparc32.h \
		${WRKSRC}/dyncallback/dyncall_callback_mips.h \
		${WRKSRC}/dyncallback/dyncall_callback_ppc64.h \
		${WRKSRC}/dyncallback/dyncall_callback_ppc32.h \
		${WRKSRC}/dyncallback/dyncall_callback_arm32_thumb.h \
		${WRKSRC}/dyncallback/dyncall_callback_arm32_arm.h \
		${WRKSRC}/dyncallback/dyncall_callback.h \
		${WRKSRC}/dyncallback/dyncall_args_x86.h \
		${WRKSRC}/dyncallback/dyncall_args_x64.h \
		${WRKSRC}/dyncallback/dyncall_args_sparc64.h \
		${WRKSRC}/dyncallback/dyncall_args_sparc32.h \
		${WRKSRC}/dyncallback/dyncall_args_mips.h \
		${WRKSRC}/dyncallback/dyncall_args_ppc64.h \
		${WRKSRC}/dyncallback/dyncall_args_ppc32.h \
		${WRKSRC}/dyncallback/dyncall_args_arm32_thumb.h \
		${WRKSRC}/dyncallback/dyncall_args_arm32_arm.h \
		${WRKSRC}/dyncallback/dyncall_args.h \
		${WRKSRC}/dynload/dynload.h \
		${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} \
		${WRKSRC}/dyncall/libdyncall_s.a \
		${WRKSRC}/dyncallback/libdyncallback_s.a \
		${WRKSRC}/dynload/libdynload_s.a \
		${STAGEDIR}${PREFIX}/lib

	${INSTALL_MAN} \
		${WRKSRC}/dyncall/dyncall.3 \
		${WRKSRC}/dyncallback/dyncallback.3 \
		${WRKSRC}/dynload/dynload.3 \
		${STAGEDIR}${MAN3PREFIX}/man/man3

.include <bsd.port.post.mk>
