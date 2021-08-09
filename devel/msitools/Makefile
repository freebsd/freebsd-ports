PORTNAME=	msitools
PORTVERSION=	0.101
CATEGORIES=	devel
MASTER_SITES=	GNOME

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
INSTALL_TARGET=	install-strip
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.mk>
