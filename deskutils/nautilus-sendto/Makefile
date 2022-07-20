PORTNAME=	nautilus-sendto
PORTVERSION=	3.8.6
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convenience application to send a file via email

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	intlhack introspection:build
USES=		compiler:c11 gettext gnome localbase meson pkgconfig tar:xz
USE_LDCONFIG=	yes
CPPFLAGS+=	-Wno-error=format-nonliteral

.include <bsd.port.mk>
