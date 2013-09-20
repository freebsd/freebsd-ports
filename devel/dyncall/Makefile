# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=	dyncall
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.dyncall.org/r${PORTVERSION}/ \
		http://www.potion-studios.com/

MAINTAINER=	tphilipp@potion-studios.com
COMMENT=	Highly dynamic multi-platform foreign function call interface library

MAN3=		dyncall.3
HAS_CONFIGURE=	yes

MAKEFILE=	BSDmakefile

# There is no install target in the BSD makefile for this version of the dyncall
# library, so install it manually.

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not install (unsupported architecture)
.endif

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
		${WRKSRC}/dyncallback/dyncall_thunk_ppc32.h \
		${WRKSRC}/dyncallback/dyncall_thunk_arm32_thumb.h \
		${WRKSRC}/dyncallback/dyncall_thunk_arm32_arm.h \
		${WRKSRC}/dyncallback/dyncall_thunk.h \
		${WRKSRC}/dyncallback/dyncall_callback_x86.h \
		${WRKSRC}/dyncallback/dyncall_callback_x64.h \
		${WRKSRC}/dyncallback/dyncall_callback_sparc32.h \
		${WRKSRC}/dyncallback/dyncall_callback_ppc32.h \
		${WRKSRC}/dyncallback/dyncall_callback_arm32_thumb.h \
		${WRKSRC}/dyncallback/dyncall_callback_arm32_arm.h \
		${WRKSRC}/dyncallback/dyncall_callback.h \
		${WRKSRC}/dyncallback/dyncall_args_x86.h \
		${WRKSRC}/dyncallback/dyncall_args_x64.h \
		${WRKSRC}/dyncallback/dyncall_args_sparc64.h \
		${WRKSRC}/dyncallback/dyncall_args_sparc32.h \
		${WRKSRC}/dyncallback/dyncall_args_ppc32.h \
		${WRKSRC}/dyncallback/dyncall_args_arm32_thumb.h \
		${WRKSRC}/dyncallback/dyncall_args_arm32_arm.h \
		${WRKSRC}/dyncallback/dyncall_args.h \
		${WRKSRC}/dynload/dynload.h \
		${PREFIX}/include
	${INSTALL_DATA} \
		${WRKSRC}/dyncall/libdyncall_s.a \
		${WRKSRC}/dyncallback/libdyncallback_s.a \
		${WRKSRC}/dynload/libdynload_s.a \
		${PREFIX}/lib

.for f3 in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/dyncall/${f3} ${MAN3PREFIX}/man/man3
.endfor

.include <bsd.port.post.mk>
