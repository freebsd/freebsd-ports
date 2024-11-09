PORTNAME=	ttyplot
DISTVERSION=	1.7.0
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Realtime plotting utility for TTY with data input from stdin
WWW=		https://github.com/tenox7/ttyplot

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	fails to build: Package 'ncursesw' not found

USES=		ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tenox7

MAKE_ARGS=	CFLAGS="${CFLAGS}" MANPREFIX="${PREFIX}/share/man"

PLIST_FILES=	bin/${PORTNAME} share/man/man1/ttyplot.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ttyplot

.include <bsd.port.mk>
