# New ports collection makefile for:	open-vm-tools for FreeBSD
# Date created:		28 Mar 2008
# Whom:			mbr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		open-vm-tools
PORTVERSION=		${BUILD_VER}
PORTREVISION=	1
CATEGORIES=		emulators kld
MASTER_SITES=		SF
DISTNAME=		open-vm-tools-${RELEASE_DATE}-${BUILD_VER}

MAINTAINER=		mbr@freebsd.org
COMMENT?=		Open VMware tools for FreeBSD VMware guests

RELEASE_DATE=		2009.05.22
BUILD_VER=		167859

GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes

CONFIGURE_ARGS+=	--without-procps --sysconfdir=${LOCALBASE}/etc
.if defined(WITHOUT_X11)
LIB_DEPENDS+=		glib-2.0:${PORTSDIR}/devel/glib20
CONFIGURE_ARGS+=	--without-x --without-gtk2 --without-gtkmm
PLIST_SUB+=		X11="@comment "
CONFLICTS=		open-vm-tools-[0-9]*
.else
.if !defined(WITHOUT_LIBNOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
.endif
.if defined(WITH_UNITY)
CONFIGURE_ENV+=		CUSTOM_URIPARSER_CPPFLAGS="-I${LOCALBASE}/include/uriparser"
LIB_DEPENDS+=		uriparser.1:${PORTSDIR}/net/uriparser
.else
CONFIGURE_ARGS+=	--disable-unity
.endif
LIB_DEPENDS+=		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"
USE_XORG=		x11 ice sm xext xineramaproto xinerama xrandr xrender \
			xtst
USE_GNOME=		gtk20 glib20
PLIST_SUB+=		X11=""
CONFLICTS=		open-vm-tools-nox11-[0-9]*
.endif

.if !defined(WITHOUT_FUSE)
LIB_DEPENDS+=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS+=	mount_fusefs:${PORTSDIR}/sysutils/fusefs-kmod
PLIST_SUB+=	FUSE=""
.else
PLIST_SUB+=	FUSE="@comment "
.endif

CONFLICTS+=		vmware-guestd[0-9]* vmware-tools[0-9]*
SUB_FILES=		pkg-message

.if defined(WITHOUT_DNET)
CONFIGURE_ARGS+=	--without-dnet
.else
LIB_DEPENDS+=		dnet:${PORTSDIR}/net/libdnet
.endif

.if defined(WITHOUT_ICU)
CONFIGURE_ARGS+=	--without-icu
.else
LIB_DEPENDS+=		icuuc:${PORTSDIR}/devel/icu
.endif

USE_RC_SUBR=		vmware-guestd.sh vmware-kmod.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.if ${ARCH} == "sparc64"
IGNORE=		not yet ported to sparc64
.endif

post-build:
	(cd ${WRKSRC}/modules && ${MAKE})

post-install:
	${MKDIR} ${PREFIX}/lib/vmware-tools/modules/drivers
	${MKDIR} ${PREFIX}/lib/vmware-tools/modules/input
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmmemctl.ko ${PREFIX}/lib/vmware-tools/modules/drivers/vmmemctl.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmxnet.ko ${PREFIX}/lib/vmware-tools/modules/drivers/vmxnet.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmhgfs.ko ${PREFIX}/lib/vmware-tools/modules/drivers/vmhgfs.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmblock.ko ${PREFIX}/lib/vmware-tools/modules/drivers/vmblock.ko
	@-kldxref ${PREFIX}/lib/vmware-tools/modules/drivers 2>/dev/null
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
