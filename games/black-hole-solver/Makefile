# $FreeBSD$

PORTNAME=	black-hole-solver
DISTVERSION=	1.8.0
CATEGORIES=	games
MASTER_SITES=	https://fc-solve.shlomifish.org/downloads/fc-solve/

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Black Hole Solitaire Solver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rinutils>0:devel/rinutils \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny

USES=		cmake tar:xz
USE_PERL5=	build

.include <bsd.port.mk>
