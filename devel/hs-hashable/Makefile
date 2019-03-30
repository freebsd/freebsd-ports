# $FreeBSD$

PORTNAME=	hashable
PORTVERSION=	1.2.7.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Class for types that can be converted to a hash value

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

FLAGS_DEFINE=			INTEGER_GMP SSE2 SSE41
FLAGS_DEFAULT_amd64=		INTEGER_GMP SSE2
FLAGS_DEFAULT_i386=		INTEGER_GMP SSE2

INTEGER_GMP_DESC=		Use integer-gmp for fast Integer instances
INTEGER_GMP_FLAG_ENABLE=	integer-gmp

SSE2_DESC=			Support for SSE 2
SSE2_FLAG_ENABLE=		sse2

SSE41_DESC=			Support for SSE 4.1
SSE41_FLAG_ENABLE=		sse41

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
