# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libosinfo
PORTVERSION=	0.2.10
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/l/i/libosinfo/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for managing OS information for virtualization

LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gnomehier glib20 libxml2 libxslt introspection:build intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-tests --disable-vala

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
