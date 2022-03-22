PORTNAME=	elliott-803
PORTVERSION=	0.1.9
DISTVERSIONPREFIX=	v
CATEGORIES=	emulators

MAINTAINER=	hsw@bitmark.com
COMMENT=	Emulator and compilers for Elliott 803 computer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang ncurses
MAKE_ARGS+=	DATADIR="${DATADIR}" PREFIX="${PREFIX}" VERSION="${PKGVERSION}"
MAKE_ENV+=	LC_ALL=en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	hxw
GH_PROJECT=	Elliott-803

.include <bsd.port.mk>
