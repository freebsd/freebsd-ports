# Created by: Thinker K.F. Li <thinker@eeebox.branda.to>
# $FreeBSD$

PORTNAME=	d-feet
PORTVERSION=	0.3.11
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	thinker@codemud.net
COMMENT=	D-Bus Python introspection debugger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext gmake gnome perl5 pkgconfig python tar:xz
USE_GNOME=	gtk30 intlhack libwnck3 pygobject3 introspection:build \
		libxml2:build
GLIB_SCHEMAS=	org.gnome.d-feet.gschema.xml
INSTALLS_ICONS=	yes
USE_PERL5=	build
USE_PYTHON=	py3kplist

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests

NO_ARCH=	yes

.include <bsd.port.mk>
