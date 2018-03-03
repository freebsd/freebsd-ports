# $FreeBSD$

PORTNAME=	sct
DISTVERSION=	0.2.1
CATEGORIES=	accessibility

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Utility to change screen temperature

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	0mp
USE_XORG=	x11 xrandr
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/sct \
		man/man1/sct.1.gz

.include <bsd.port.mk>
