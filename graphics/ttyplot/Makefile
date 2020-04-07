# $FreeBSD$

PORTNAME=	ttyplot
DISTVERSION=	1.4
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Realtime plotting utility for TTY with data input from stdin

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	tenox7

MAKE_ARGS=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
