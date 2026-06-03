PORTNAME=	msitools
DISTVERSION=	0.106
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Inspect and build Windows Installer (.MSI) files
WWW=		https://wiki.gnome.org/msitools

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/copyright

LIB_DEPENDS=	libgcab-1.0.so:archivers/gcab \
		libgsf-1.so:devel/libgsf \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	gsed:textproc/gsed

USES=		bison gnome meson perl5 pkgconfig shebangfix tar:xz vala:build
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection libxml2
SHEBANG_FILES=	tools/msidiff.in \
		tools/msidump.in
PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	${REINPLACE_CMD} 's|sed|gsed|g' ${WRKSRC}/tests/wixl.bats

.include <bsd.port.mk>
