# New ports collection makefile for: dyncall
# Date created:        05 April 2008
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=	dyncall
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	http://www.dyncall.org/r${PORTVERSION}/

MAINTAINER=	tphilipp@potion-studios.com
COMMENT=	Highly dynamic multi-platform foreign function call interface library

MAN3=		dyncall.3
HAS_CONFIGURE=	yes

MAKEFILE=	BSDmakefile

# There is no install target in the BSD makefile of version 0.5 of the dyncall library, so
# install it manually.

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=		Does not install (unsupported architecture)
.endif

do-install:
	${INSTALL_DATA}	${WRKSRC}/dyncall/dyncall.h \
		${WRKSRC}/dyncall/dyncall_*.h \
		${WRKSRC}/dyncallback/dyncall_*.h \
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
