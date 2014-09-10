# $FreeBSD$

PORTNAME=	unix-time
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Unix time parser/formatter and utilities

LICENSE=	BSD3CLAUSE

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

.if ${OSVERSION} >= 901000 && ${OSVERSION} < 902001 && ${ARCH} == i386
EXTRA_PATCHES+=		${PATCHDIR}/nopatch-unix-time.cabal
.endif

.include <bsd.port.mk>
