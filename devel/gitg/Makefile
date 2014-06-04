# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	gitg
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GTK-based git repository viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		git:${PORTSDIR}/devel/git

CONFLICTS=	gitg0-[0-9]*

USES=		tar:xz gettext gmake pkgconfig pathfix libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-maintainer-mode \
		--enable-compile-warnings=no
USE_GNOME=	glib20 gtk30 gtksourceview3
INSTALL_TARGET=	install-strip

INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	org.gnome.gitg.gschema.xml

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

.include <bsd.port.mk>
