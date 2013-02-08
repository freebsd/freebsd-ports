# $FreeBSD$

PORTNAME=	terminfo
PORTVERSION=	0.3.2.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell bindings to the terminfo library

LICENSE=	BSD

USE_NCURSES=	yes

CONFIGURE_ARGS+=	--configure-option=--with-curses-includes=${NCURSESINC} \
			--configure-option=--with-curses-libraries=${NCURSESLIB}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
