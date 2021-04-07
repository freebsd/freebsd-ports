PORTNAME=	msitools
PORTVERSION=	0.100
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Inspect and build Windows Installer (.MSI) files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcab-1.0.so:archivers/gcab \
		libgsf-1.so:devel/libgsf \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	bash:shells/bash

USES=		bison:alias gmake gnome libtool pkgconfig shebangfix tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxml2
GNU_CONFIGURE=	yes
SHEBANG_FILES=	tools/msidiff.in \
		tools/msidump.in
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
