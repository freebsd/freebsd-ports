PORTNAME=	eksanos
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Simple TicTacToe game written for elementary OS
WWW=		https://github.com/eksanos/eksanos

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgranite-7.so:x11-toolkits/granite7 \
		libhandy-1.so:x11-toolkits/libhandy

USES=		gnome meson pkgconfig vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
USE_GNOME=	glib20 gtk40 libadwaita

.include <bsd.port.mk>
