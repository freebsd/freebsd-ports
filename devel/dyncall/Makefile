# New ports collection makefile for: dyncall
# Date created:        05 April 2008
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=		dyncall
PORTVERSION=		0.1
CATEGORIES=		devel
MASTER_SITES=		http://www.dyncall.org/r0.1/

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		Highly dynamic multi-platform foreign function call interface library

HAS_CONFIGURE=		yes

MAKEFILE=		${WRKSRC}/BSDmakefile

# There is no install target in the BSD makefile of version 0.1 of the dyncall library, so
# install it manually.

do-install:
	${CP} ${WRKSRC}/dyncall/dyncall.h           ${PREFIX}/include/dyncall.h
	${CP} ${WRKSRC}/dyncall/dyncall_callf.h     ${PREFIX}/include/dyncall_callf.h
	${CP} ${WRKSRC}/dyncall/dyncall_config.h    ${PREFIX}/include/dyncall_config.h
	${CP} ${WRKSRC}/dyncall/dyncall_macros.h    ${PREFIX}/include/dyncall_macros.h
	${CP} ${WRKSRC}/dyncall/dyncall_signature.h ${PREFIX}/include/dyncall_signature.h
	${CP} ${WRKSRC}/dyncall/dyncall_types.h     ${PREFIX}/include/dyncall_types.h
	${CP} ${WRKSRC}/dyncall/dyncall_value.h     ${PREFIX}/include/dyncall_value.h
	${CP} ${WRKSRC}/dynload/dynload.h           ${PREFIX}/include/dynload.h
	${CP} ${WRKSRC}/dyncall/libdyncall_s.a      ${PREFIX}/lib/libdyncall_s.a
	${CP} ${WRKSRC}/dynload/libdynload_s.a      ${PREFIX}/lib/libdynload_s.a

.include <bsd.port.mk>
