PORTNAME=	hledger-ui
DISTVERSION=	1.52
CATEGORIES=	finance haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	UI for hledger, the accounting software package
WWW=		https://hledger.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_16=	compilation fails: ghc SEGVs, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=294032

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		cabal
USE_LOCALE=	C.UTF-8

.include <bsd.port.mk>
