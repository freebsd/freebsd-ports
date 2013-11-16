# Created by: mbr@FreeBSD.org
# $FreeBSD$

PORTNAME=		open-vm-tools
PORTVERSION=		${BUILD_VER}
PORTREVISION=		4
PORTEPOCH=		1
CATEGORIES=		emulators
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/stable-9.2.x
DISTNAME=		open-vm-tools-${RELEASE_VER}-${BUILD_VER}

MAINTAINER=		swills@FreeBSD.org
COMMENT?=		Open VMware tools for FreeBSD VMware guests

LICENSE=		LGPL21
LICENSE_FILE=		${WRKSRC}/COPYING

RELEASE_VER=		9.2.3
BUILD_VER=		1031360

WRKSRC=			${WRKDIR}/open-vm-tools-${RELEASE_VER}-${BUILD_VER}
GNU_CONFIGURE=		yes
USES=			pkgconfig kmod
USE_GNOME=		glib20
USE_LDCONFIG=		yes
CPPFLAGS+=		-Wno-deprecated-declarations
KMODDIR=		${PREFIX}/lib/vmware-tools/modules/drivers

SSP_UNSAFE=		kernel module does not support ssp

CONFIGURE_ARGS+=	--without-procps --sysconfdir=${LOCALBASE}/etc
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x --without-gtk2 --without-gtkmm
PLIST_SUB+=		X11="@comment "
CONFLICTS=		open-vm-tools-[0-9]*
.else
.if !defined(WITHOUT_LIBNOTIFY)
LIB_DEPENDS+=		libnotify.so:${PORTSDIR}/devel/libnotify
.endif
CONFIGURE_ARGS+=	--with-x
LDFLAGS+=		-L${LOCALBASE}/lib
USE_XORG=		x11 ice sm xext xineramaproto xinerama xrandr xrender \
			xtst
USE_GNOME+=		gtk20 gtkmm24
PLIST_SUB+=		X11=""
CONFLICTS=		open-vm-tools-nox11-[0-9]*
.endif

.if !defined(WITHOUT_FUSE)
USES+=		fuse
PLIST_SUB+=	FUSE=""
.else
PLIST_SUB+=	FUSE="@comment "
.endif

CONFLICTS+=		vmware-guestd[0-9]* vmware-tools[0-9]*
SUB_FILES=		pkg-message

.if defined(WITHOUT_DNET)
CONFIGURE_ARGS+=	--without-dnet
.else
LIB_DEPENDS+=		libdnet.so:${PORTSDIR}/net/libdnet
.endif

.if defined(WITHOUT_ICU)
CONFIGURE_ARGS+=	--without-icu
.else
LIB_DEPENDS+=		libicuuc.so:${PORTSDIR}/devel/icu
.endif

USE_RC_SUBR=		vmware-guestd vmware-kmod

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
IGNORE=		not yet ported to sparc64
.endif

post-build:
	(cd ${WRKSRC}/modules && env ${MAKE_ENV} ${MAKE} ${MAKE_ARGS})

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/input
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmmemctl.ko ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers/vmmemctl.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmxnet.ko ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers/vmxnet.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmhgfs.ko ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers/vmhgfs.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmblock.ko ${STAGEDIR}${PREFIX}/lib/vmware-tools/modules/drivers/vmblock.ko
	${MKDIR} ${STAGEDIR}${PREFIX}/share/open-vm-tools/scripts/vmware/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/open-vm-tools/scripts/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/open-vm-tools/tests/

.include <bsd.port.post.mk>
