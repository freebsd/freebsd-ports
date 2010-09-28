# New ports collection makefile for: dyncall
# Date created:        05 April 2008
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=	dyncall
PORTVERSION=	0.6
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=		Does not install (unsupported architecture)
.endif

do-install:
	${INSTALL_DATA}	${WRKSRC}/dyncall/dyncall.h \
		${WRKSRC}/dyncall/dyncall_alloc.h \
		${WRKSRC}/dyncall/dyncall_vector.h \
		${WRKSRC}/dyncall/dyncall_types.h \
		${WRKSRC}/dyncall/dyncall_value.h \
		${WRKSRC}/dyncall/dyncall_callf.h \
		${WRKSRC}/dyncall/dyncall_callvm.h \
		${WRKSRC}/dyncall/dyncall_config.h \
		${WRKSRC}/dyncall/dyncall_macros.h \
		${WRKSRC}/dyncall/dyncall_signature.h \
		${WRKSRC}/dyncallback/dyncall_alloc_wx.h \
		${WRKSRC}/dyncallback/dyncall_args.h \
		${WRKSRC}/dyncallback/dyncall_callback.h \
		${WRKSRC}/dyncallback/dyncall_thunk.h \
		${WRKSRC}/dyncallback/dyncall_thunk_arm32_arm.h \
		${WRKSRC}/dyncallback/dyncall_thunk_arm32_thumb.h \
		${WRKSRC}/dyncallback/dyncall_thunk_ppc32.h \
		${WRKSRC}/dyncallback/dyncall_thunk_x86.h \
		${WRKSRC}/dyncallback/dyncall_thunk_x64.h \
		${WRKSRC}/dynload/dynload.h \
		${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/dyncall/libdyncall_s.a \
		${WRKSRC}/dyncallback/libdyncallback_s.a \
		${WRKSRC}/dynload/libdynload_s.a \
		${PREFIX}/lib

.for f3 in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/doc/${f3} ${MAN3PREFIX}/man/man3
.endfor

.include <bsd.port.post.mk>
