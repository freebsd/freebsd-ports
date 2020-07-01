# $FreeBSD$

PORTNAME=	Elliott-803
PORTVERSION=	0.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	emulators

MAINTAINER=	hsw@bitmark.com
COMMENT=	Emulator and compilers for Elliott 803 computer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses
MAKEFILE=	BSDmakefile
MAKE_ARGS+=	PREFIX="${PREFIX}" VERSION="${PKGVERSION}"
MAKE_ENV+=	LC_ALL=en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	hxw

.include <bsd.port.mk>
