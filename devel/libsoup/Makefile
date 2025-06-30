PORTNAME=	libsoup
DISTVERSION=	2.74.3
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C
WWW=		https://libsoup.org/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib-networking>=2.29.18:net/glib-networking
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libpsl.so:dns/libpsl
RUN_DEPENDS=	glib-networking>=2.29.18:net/glib-networking

USES=		cpe gettext gnome localbase meson \
		pkgconfig python:build sqlite ssl tar:xz
USE_GNOME=	glib20 intlhack introspection:build \
		libxml2
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome

OPTIONS_DEFINE=			DOCS SMB
OPTIONS_SINGLE=			GSSAPI
OPTIONS_SINGLE_GSSAPI=		GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=		SMB GSSAPI_${${SSL_DEFAULT} == base :?BASE :NONE}

DOCS_MESON_TRUE=		gtk_doc
DOCS_BUILD_DEPENDS=		gtkdoc-scan:textproc/gtk-doc
DOCSDIR=			${PREFIX}/share/gtk-doc/html/${PORTNAME}-${RELVERSION}

# Circular dependency samba -> tracker -> libsoup if the SPOTLIGHT
# option is turned on in samba. Since samba is a **runtime** only
# dependency, we can just tell it to be used. However, the Meson
# build does a **build** time check for samba (even though the code does
# a run-time check, too).
#
# Runtime deps still trigger a build / a dependency cycle, so as
# a stopgap, patch it in, don't build anything, and inform the
# user via pkg-message.
# SMB_USES=			samba:run
SMB_MESON_ENABLED=		ntlm

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_MESON_ON=		-Dgssapi=enabled -Dkrb5_config=${KRB5CONFIG}

GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_MESON_ON=	-Dgssapi=enabled -Dkrb5_config=${KRB5CONFIG}

GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_MESON_ON=		-Dgssapi=enabled -Dkrb5_config=${KRB5CONFIG}

GSSAPI_NONE_MESON_DISABLED=	gssapi

MESON_ARGS=	-Dvapi=disabled \
		-Dsysprof=disabled \
		-Dtests=false \
		-Dgnome=true \
		-Dbrotli=disabled

# RELVERSION also used in DOCSDIR, above
RELVERSION=	2.4
LIBVERSION=	1.11.2
PLIST_SUB=	VERSION=${RELVERSION} LIBVERSION=${LIBVERSION}

PORTSCOUT=	limit:^2\.[0-9]?[02468]\.

post-patch:
	${REINPLACE_CMD} \
		-e 's+@@NTLM_AUTH@@+${LOCALBASE}/bin/ntlm_auth+' \
		${WRKSRC}/meson.build

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}/NEWS

.include <bsd.port.mk>
