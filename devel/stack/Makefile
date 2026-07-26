PORTNAME=	stack
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform program for developing Haskell programs
WWW=		https://www.haskellstack.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.10.3:lang/ghc910
LIB_DEPENDS=	libinotify.so:devel/libinotify
RUN_DEPENDS=	${LOCALBASE}/lib/compat/libffi.so.6:devel/libffi321 \
		${LOCALBASE}/lib/compat/libffi.so.7:devel/libffi33 \
		ca_root_nss>0:security/ca_root_nss \
		gmake:devel/gmake

USES=		cabal gmake iconv:wchar_t perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	commercialhaskell
USE_PERL5=	run

CABAL_FLAGS=	-support_aesni
CABAL_PROJECT=	remove

BINARY_ALIAS=	ghc=ghc-9.10.3

.include <bsd.port.pre.mk>

.if !${ARCH:Mpowerpc64*}
LIB_DEPENDS+=	libncursesw.so.8:misc/compat12x
.endif

.include <bsd.port.post.mk>
