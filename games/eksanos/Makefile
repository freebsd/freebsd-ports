PORTNAME=	eksanos
PORTVERSION=	1.1.0
CATEGORIES=	games

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Simple TicTacToe game written for elementary OS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy

USES=		gnome meson pkgconfig vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
USE_GNOME=	glib20 gtk30

.include <bsd.port.mk>
