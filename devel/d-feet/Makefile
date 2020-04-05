# Created by: Thinker K.F. Li <thinker@eeebox.branda.to>
# $FreeBSD$

PORTNAME=	d-feet
PORTVERSION=	0.3.15
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	D-Bus Python introspection debugger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext gnome meson pkgconfig python:3.5+ tar:xz
USE_GNOME=	gtk30 intlhack libwnck3 pygobject3 introspection:build \
		libxml2:build
GLIB_SCHEMAS=	org.gnome.dfeet.gschema.xml
INSTALLS_ICONS=	yes
USE_PYTHON=	py3kplist

MESON_ARGS=	-Dtests=false

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		-e 's|%%PYTHON_VERSION%%|${PYTHON_VERSION}|' \
		${WRKSRC}/meson.build

post-install:
.for locale in cs de el es hu pl pt_BR sv
	${RLN} ${STAGEDIR}${PREFIX}/share/help/C/d-feet/figures/icon.png \
		${STAGEDIR}${PREFIX}/share/help/${locale}/d-feet/figures/icon.png
.endfor

.include <bsd.port.mk>
