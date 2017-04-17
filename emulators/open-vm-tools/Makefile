# Created by: mbr@FreeBSD.org
# $FreeBSD$

PORTNAME=		open-vm-tools
PORTVERSION=		${RELEASE_VER}
PORTREVISION=		2
PORTEPOCH=		2
MASTER_SITES=		https://github.com/vmware/open-vm-tools/files/590760/
DISTNAME=		open-vm-tools-${RELEASE_VER}-${BUILD_VER}
CATEGORIES=		emulators

MAINTAINER=		swills@FreeBSD.org
COMMENT?=		Open VMware tools for FreeBSD VMware guests

LICENSE=		LGPL21
LICENSE_FILE=		${WRKSRC}/COPYING

RELEASE_VER=		10.1.0
BUILD_VER=		4449150

OPTIONS_DEFINE=		X11 LIBNOTIFY UNITY FUSE DNET ICU
OPTIONS_DEFAULT=	X11 LIBNOTIFY FUSE DNET ICU
OPTIONS_SUB=

DNET_DESC=		libdnet support
LIBNOTIFY_DESC=		Desktop notification support
UNITY_DESC=		liburiparser support

# TODO add USE_GITHUB=yes after switching to USES=autoreconf

X11_CONFIGURE_WITH=	x gtk2 gtkmm
X11_USE=		xorg=x11,ice,sm,xext,xineramaproto,xinerama,xrandr,xrender,xtst,xi \
			gnome=gtk20,gtkmm24,gdkpixbuf2
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
LIBNOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
UNITY_CONFIGURE_ENV=	CUSTOM_URIPARSER_CPPFLAGS="-I${LOCALBASE}/include/uriparser"
UNITY_LIB_DEPENDS=	liburiparser.so:net/uriparser
UNITY_CONFIGURE_ENABLE=	unity
DNET_CONFIGURE_WITH=	dnet
DNET_LIB_DEPENDS=	libdnet.so:net/libdnet
ICU_CONFIGURE_WITH=	icu
ICU_LIB_DEPENDS=	libicuuc.so:devel/icu

WRKSRC=			${WRKDIR}/open-vm-tools-${RELEASE_VER}-${BUILD_VER}/open-vm-tools
GNU_CONFIGURE=		yes
USE_GNOME=		glib20
# TODO add autoreconf when included files are compatible
USES=			fuse gettext-runtime kmod libtool pathfix pkgconfig

LIB_DEPENDS=		libmspack.so:archivers/libmspack \
			libxerces-c.so.3:textproc/xerces-c3 \
			libxml-security-c.so:security/apache-xml-security-c

USE_LDCONFIG=		yes
CPPFLAGS+=		-Wno-deprecated-declarations
LDFLAGS=		-L${LOCALBASE}/lib

SSP_UNSAFE=		kernel module does not support ssp

CONFIGURE_ARGS+=	--disable-grabbitmqproxy --disable-deploypkg \
			--disable-vgauth --without-procps \
			--sysconfdir=${LOCALBASE}/etc

CONFLICTS+=		vmware-guestd[0-9]* vmware-tools[0-9]*

USE_RC_SUBR=		vmware-guestd vmware-kmod

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
CONFLICTS=		open-vm-tools-nox11-[0-9]*
.else
CONFLICTS=		open-vm-tools-[0-9]*
.endif

ONLY_FOR_ARCHS=		i386 amd64

CONFIGURE_ENV+=		SYSDIR=${SRC_BASE}/sys

.include <bsd.port.pre.mk>

post-build:
	cd ${WRKSRC}/modules && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/input
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmblock.ko ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers/vmblock.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmmemctl.ko ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers/vmmemctl.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmxnet.ko ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers/vmxnet.ko
	${MKDIR} ${STAGEDIR}${PREFIX}/share/open-vm-tools/scripts/vmware/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/open-vm-tools/scripts/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/open-vm-tools/tests/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.conf.d

.include <bsd.port.post.mk>
