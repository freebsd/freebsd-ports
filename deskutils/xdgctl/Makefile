PORTNAME=	xdgctl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	deskutils

MAINTAINER=	l.lux@magenta.de
COMMENT=	TUI for managing XDG default applications
WWW=		https://github.com/mitjafelicijan/xdgctl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake gnome pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	mitjafelicijan
GH_TAGNAME=	v1.0

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/xdgctl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
	${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
