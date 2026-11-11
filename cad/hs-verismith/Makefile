PORTNAME=	verismith
DISTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	cad haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Random verilog generation and simulator testing
WWW=		https://hackage.haskell.org/package/verismith/ \
		https://github.com/ymherklotz/verismith/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.10.3:lang/ghc910

USES=		cabal dos2unix
DOS2UNIX_FILES=	_cabal_deps/text-2.1.4/simdutf/simdutf.h

BROKEN_aarch64=		compilation fails, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=300682

PORTSCOUT=	limit:^.*[0-9]\.[0-9] # prevent fpga20

.include <bsd.port.mk>
