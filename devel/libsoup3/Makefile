PORTNAME=	libsoup
PORTVERSION=	3.6.5
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome
PKGNAMESUFFIX=	3

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	HTTP client/server library for GNOME
WWW=		https://gitlab.gnome.org/GNOME/libsoup

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib-networking>0:net/glib-networking \
		${PYTHON_PKGNAMEPREFIX}gi-docgen>=0:textproc/py-gi-docgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}smartypants>0:textproc/py-smartypants@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typogrify>0:textproc/py-typogrify@${PY_FLAVOR}

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libnghttp2.so:www/libnghttp2 \
		libpsl.so:dns/libpsl

RUN_DEPENDS=	glib-networking>0:net/glib-networking

USES=		cpe gettext gnome meson pkgconfig python:build sqlite \
		ssl tar:xz
USE_GNOME=	glib20 introspection:build libxml2
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome

OPTIONS_DEFINE=			VAPI
OPTIONS_SINGLE=			GSSAPI
OPTIONS_SINGLE_GSSAPI=		GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=		GSSAPI_${${SSL_DEFAULT} == base :?BASE :NONE} VAPI
OPTIONS_SUB=			yes

MESON_ARGS=	-Dtests=false \
		-Dinstalled_tests=false \
		-Dsysprof=disabled \
		-Dpkcs11_tests=disabled \
		-Dfuzzing=disabled \
		-Dautobahn=disabled \
		-Dtls_check=true \
		-Dntlm=disabled

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_MESON_ON=		-Dgssapi=enabled
.if !exists(/usr/libdata/pkgconfig/mit-krb5.pc)
GSSAPI_BASE_VARS=		pkgconfig_paths=${PATCHDIR}
.endif

GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_MESON_ON=	-Dgssapi=enabled

GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_MESON_ON=		-Dgssapi=enabled

GSSAPI_NONE_MESON_DISABLED=	gssapi

VAPI_USES=			vala:build
VAPI_MESON_ENABLED=		vapi

BINARY_ALIAS=	python3=${PYTHON_CMD}

.if !exists(/usr/libdata/pkgconfig/mit-krb5.pc)
post-install-GSSAPI_BASE-on:
	${SED} -e 's|krb5-gssapi,||' \
		${BUILD_WRKSRC}/meson-private/libsoup-3.0.pc > ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libsoup-3.0.pc
.endif

.include <bsd.port.mk>
