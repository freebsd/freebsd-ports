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

USES=		cabal

PORTSCOUT=	limit:^.*[0-9]\.[0-9] # prevent fpga20

.include <bsd.port.mk>
