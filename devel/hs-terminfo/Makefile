# $FreeBSD$

PORTNAME=	terminfo
PORTVERSION=	0.3.2.5
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell bindings to the terminfo library

LICENSE=	BSD

USES=		ncurses

CONFIGURE_ARGS+=	--configure-option=--with-curses-includes=${NCURSESINC} \
			--configure-option=--with-curses-libraries=${NCURSESLIB}

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
