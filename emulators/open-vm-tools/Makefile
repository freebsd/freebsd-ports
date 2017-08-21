# Created by: mbr@FreeBSD.org
# $FreeBSD$

PORTNAME=		open-vm-tools
PORTVERSION=		${RELEASE_VER}
DISTVERSIONPREFIX=	stable-
PORTEPOCH=		2
PORTREVISION=		1
CATEGORIES=		emulators

MAINTAINER=		jpaetzel@FreeBSD.org
COMMENT?=		Open VMware tools for FreeBSD VMware guests

LICENSE=		LGPL21
LICENSE_FILE=		${WRKSRC}/COPYING

LIB_DEPENDS=		libmspack.so:archivers/libmspack \
			libxerces-c.so:textproc/xerces-c3 \
			libxml-security-c.so:security/apache-xml-security-c

RELEASE_VER=		10.1.5
BUILD_VER=		5055683

OPTIONS_DEFINE=		DNET ICU LIBNOTIFY OPENSSL X11
OPTIONS_DEFAULT=	DNET ICU LIBNOTIFY OPENSSL X11

OPTIONS_SUB=

DNET_DESC=		libdnet support
LIBNOTIFY_DESC=		Desktop notification support

X11_CONFIGURE_WITH=	x gtk2 gtkmm
X11_USE=		xorg=ice,sm,x11,xext,xi,xinerama,xineramaproto,xrandr,xrender,xtst \
			gnome=gdkpixbuf2,gtk20,gtkmm24
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
LIBNOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
DNET_CONFIGURE_WITH=	dnet
DNET_LIB_DEPENDS=	libdnet.so:net/libdnet
ICU_CONFIGURE_WITH=	icu
ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
OPENSSL_CONFIGURE_WITH=	ssl

WRKSRC_SUBDIR=		open-vm-tools

GNU_CONFIGURE=		yes
USE_GNOME=		glib20
USES=			autoreconf:-iv fuse gettext-runtime kmod libtool localbase pathfix pkgconfig

USE_GITHUB=		yes
GH_ACCOUNT=		vmware

USE_LDCONFIG=		yes
CPPFLAGS+=		-Wno-deprecated-declarations

SSP_UNSAFE=		kernel module does not support ssp

CONFIGURE_ARGS+=	--disable-grabbitmqproxy \
			--disable-vgauth --without-procps \
			--sysconfdir=${PREFIX}/etc

CONFLICTS+=		vmware-guestd[0-9]* vmware-tools[0-9]*

USE_RC_SUBR=		vmware-guestd vmware-kmod

INSTALL_TARGET=		install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
CONFLICTS=		open-vm-tools-nox11-[0-9]*
.else
CONFLICTS=		open-vm-tools-[0-9]*
.endif

ONLY_FOR_ARCHS=		i386 amd64

CONFIGURE_ENV+=		SYSDIR=${SRC_BASE}/sys

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@"\
		${WRKSRC}/lib/guestApp/guestApp.c

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
