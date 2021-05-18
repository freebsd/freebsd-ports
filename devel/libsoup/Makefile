# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	libsoup
PORTVERSION=	2.72.0
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib-networking>=2.29.18:net/glib-networking
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libpsl.so:dns/libpsl
RUN_DEPENDS=	glib-networking>=2.29.18:net/glib-networking

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=			SMB
OPTIONS_SINGLE=			GSSAPI
OPTIONS_SINGLE_GSSAPI=		GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=		SMB GSSAPI_${${SSL_DEFAULT} == base :?BASE :NONE}

SMB_USES=			samba:build
SMB_MESON_ENABLED=		ntlm

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_MESON_ON=		-Dgssapi=enabled -Dkrb5_config=${KRB5CONFIG}

GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_MESON_ON=	-Dgssapi=enabled -Dkrb5_config=${KRB5CONFIG}

GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_MESON_ON=		-Dgssapi=enabled -Dkrb5_config=${KRB5CONFIG}

GSSAPI_NONE_MESON_DISABLED=	gssapi

USES=		gettext gnome localbase meson \
		pkgconfig python:3.6+,build sqlite ssl tar:xz
USE_GNOME=	glib20 intlhack introspection:build \
		libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Dvapi=disabled \
		-Dsysprof=disabled \
		-Dtests=false \
		-Dgnome=true \
		-Dbrotli=disabled

LIBVERSION=	1.11.0
PLIST_SUB=	VERSION="2.4" LIBVERSION=${LIBVERSION}

.include <bsd.port.mk>
