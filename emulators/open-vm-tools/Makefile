PORTNAME=	open-vm-tools
PORTVERSION=	12.5.2
DISTVERSIONPREFIX=	stable-
PORTEPOCH=	2
CATEGORIES=	emulators

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open VMware tools for FreeBSD VMware guests ${${FLAVOR}_COMMENT}
WWW=		https://github.com/vmware/open-vm-tools

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 i386

LIB_DEPENDS=	libdnet.so:net/libdnet
RUN_DEPENDS=	open-vm-kmod>0:emulators/open-vm-kmod

FLAVORS=			default nox11
default_CONFLICTS_INSTALL=	open-vm-tools-nox11
nox11_PKGNAMESUFFIX=		-nox11
nox11_CONFLICTS_INSTALL=	open-vm-tools
nox11_COMMENT=			(without X11)

USES=		autoreconf gettext-runtime gnome libtool localbase \
		pathfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	vmware
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_RC_SUBR=	vmware-guestd vmware-kmod

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-vgauth \
		--enable-containerinfo=no \
		--sysconfdir=${PREFIX}/etc \
		--without-icu \
		--without-kernel-modules

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-Wno-deprecated-declarations

WRKSRC_SUBDIR=	open-vm-tools

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS DEPLOYPKG FUSE LIBNOTIFY OPENSSL X11
OPTIONS_DEFAULT=DOCS FUSE LIBNOTIFY OPENSSL X11
.if ${FLAVOR:U} == nox11
OPTIONS_EXCLUDE:=	LIBNOTIFY X11
.endif
OPTIONS_SUB=

DEPLOYPKG_DESC=		DeployPkg plugin
LIBNOTIFY_DESC=		Desktop notification support

DEPLOYPKG_LIB_DEPENDS=	libmspack.so:archivers/libmspack
DEPLOYPKG_CONFIGURE_ENABLE=	deploypkg
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CONFIGURE_ENABLE=	docs
FUSE_USES=		fuse
LIBNOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
OPENSSL_CONFIGURE_WITH=	ssl
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
X11_USES=		desktop-file-utils xorg
X11_USE=		GNOME=gdkpixbuf,gdkpixbuf2xlib,gtk30,gtkmm30 \
			XORG=ice,sm,x11,xext,xi,xinerama,xorgproto,xrandr,xrender,xtst
X11_CONFIGURE_WITH=	gtk3 gtkmm3 x

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@"\
		${WRKSRC}/lib/guestApp/guestApp.c

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/input
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tools.conf \
		${STAGEDIR}${DATADIR}/tools.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/share/open-vm-tools/scripts/vmware/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/open-vm-tools/tests/

.include <bsd.port.mk>
