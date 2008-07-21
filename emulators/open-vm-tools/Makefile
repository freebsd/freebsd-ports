# New ports collection makefile for:	open-vm-tools for FreeBSD
# Date created:		28 Mar 2008
# Whom:			mbr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		open-vm-tools
PORTVERSION=		${BUILD_VER}
PORTREVISION=		1
CATEGORIES=		emulators
DISTNAME=		open-vm-tools-${RELEASE_DATE}-${BUILD_VER}
MASTER_SITES=		SF

MAINTAINER=		mbr@freebsd.org
COMMENT?=		Open VMware tools for FreeBSD VMware guests

RELEASE_DATE=		2008.07.01
BUILD_VER=		102166

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-procps
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
.else
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ENV=		LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"
USE_XORG=		x11 ice xineramaproto xinerama xrandr xtst
USE_GNOME=		gtk20
PLIST_SUB+=		X11=""
PLIST=			${PKGDIR}/pkg-plist-x11
.endif

CONFLICTS=		vmware-guestd* vmware-tools*

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

.if ${OSVERSION} < 600000
PLIST_SUB+=	FIVEONLY="@comment "
.else
PLIST_SUB+=	FIVEONLY=""
.endif

post-patch:
.if defined(WITHOUT_X11)
	cd ${WRKSRC} && patch < ${FILESDIR}/optpatch-nox11
.endif

post-build:
	cd ${WRKSRC}/modules && make

post-install:
	${MKDIR} -p ${PREFIX}/lib/vmware-tools/modules/drivers
	${MKDIR} -p ${PREFIX}/lib/vmware-tools/modules/input
	${MKDIR} -p ${PREFIX}/share/vmware-tools
	${INSTALL} ${WRKSRC}/guestd/vmware-guestd ${PREFIX}/bin/vmware-guestd
.if ${OSREL} >= 6
	${INSTALL} ${WRKSRC}/hgfsmounter/mount.vmhgfs ${PREFIX}/sbin/mount_vmhgfs
.endif
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmmemctl.ko ${PREFIX}/lib/vmware-tools/modules/drivers/vmmemctl.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmxnet.ko ${PREFIX}/lib/vmware-tools/modules/drivers/vmxnet.ko
.if ${OSREL} >= 6
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmhgfs.ko ${PREFIX}/lib/vmware-tools/modules/drivers/vmhgfs.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmblock.ko ${PREFIX}/lib/vmware-tools/modules/drivers/vmblock.ko
	@-kldxref ${PREFIX}/lib/vmware-tools/modules/drivers 2>/dev/null
.endif
.if !defined(WITHOUT_X11)
	${INSTALL} ${WRKSRC}/toolbox/vmware-toolbox ${LOCALBASE}/sbin/vmware-toolbox
	${INSTALL} ${WRKSRC}/vmware-user/vmware-user ${LOCALBASE}/sbin/vmware-user
.endif

.include <bsd.port.post.mk>
