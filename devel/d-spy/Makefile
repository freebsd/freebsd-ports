PORTNAME=	d-spy
PORTVERSION=	1.6.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus explorer
WWW=		https://gitlab.gnome.org/GNOME/d-spy

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	gtk40 libadwaita
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	org.gnome.dspy.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
