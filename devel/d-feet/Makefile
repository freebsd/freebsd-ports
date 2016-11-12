# Created by: Thinker K.F. Li <thinker@eeebox.branda.to>
# $FreeBSD$

PORTNAME=	d-feet
PORTVERSION=	0.3.11
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	thinker@codemud.net
COMMENT=	D-Bus python introspection debugger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

NO_ARCH=	yes
USES=		gettext gmake gnome perl5 pkgconfig python:2.7+ tar:xz
USE_GNOME=	gtk30 intlhack introspection:build libxml2:build libwnck3
GNU_CONFIGURE=	yes
USE_PERL5=	build
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.d-feet.gschema.xml

# testsuite needs bin/pep8
CONFIGURE_ARGS+=--disable-tests

.include <bsd.port.mk>
