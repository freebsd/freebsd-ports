# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	c2hs
PORTVERSION=	0.28.6
PORTREVISION=	6
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	C->Haskell FFI tool that gives some cross-language type safety

LICENSE=	GPLv2

DEPRECATED=	Was used as BUILD_DEPENDS, not useful on its own
EXPIRATION_DATE=2021-03-27

USES=		cabal

USE_CABAL=	alex-3.2.5 dlist-0.8.0.7 happy-1.19.12 language-c-0.8.3 syb-0.7.1

PLIST_FILES=	man/man1/c2hs.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man1/c2hs.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
