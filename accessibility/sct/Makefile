PORTNAME=	sct
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	accessibility

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Utility to change screen temperature
WWW=		https://github.com/0mp/sct

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	0mp
USE_XORG=	x11 xrandr
MAKE_ARGS=	MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/sct \
		share/man/man1/sct.1.gz

.include <bsd.port.mk>
