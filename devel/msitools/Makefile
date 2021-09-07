PORTNAME=	msitools
DISTVERSION=	0.101
CATEGORIES=	devel
MASTER_SITES=	GNOME

PATCH_SITES=	https://gitlab.gnome.org/GNOME/msitools/-/commit/
PATCHFILES=	b08275d549bb12a09a420ef9ccaeb0974e00008a.patch:-p1 \
		25c4353cf173cddeb76c0a2dd6621bcb753cabf8.patch:-p1

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Inspect and build Windows Installer (.MSI) files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/copyright

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgcab-1.0.so:archivers/gcab \
		libgsf-1.so:devel/libgsf \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	bash:shells/bash

USES=		bison gnome libtool meson perl5 pkgconfig shebangfix tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection libxml2
SHEBANG_FILES=	tools/msidiff.in \
		tools/msidump.in
PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.mk>
