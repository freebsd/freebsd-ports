PORTNAME=	libgnt
PORTVERSION=	2.14.1
CATEGORIES=	devel
MASTER_SITES=	SF/pidgin/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Toolkit based on glib and ncurses for text-mode user interfaces

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

USES=		gettext-runtime gnome meson pkgconfig tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
