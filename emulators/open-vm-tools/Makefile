# New ports collection makefile for:	open-vm-tools for FreeBSD
# Date created:		28 Mar 2008
# Whom:			mbr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		open-vm-tools
PORTVERSION=		${BUILD_VER}
PORTREVISION=		7
CATEGORIES=		emulators kld
MASTER_SITES=		SF
DISTNAME=		open-vm-tools-${RELEASE_DATE}-${BUILD_VER}

MAINTAINER=		mbr@freebsd.org
COMMENT?=		Open VMware tools for FreeBSD VMware guests

RELEASE_DATE=		2008.07.01
BUILD_VER=		102166

GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes

CONFIGURE_ARGS+=	--without-procps
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
CONFLICTS=		open-vm-tools-[0-9]*
.else
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ENV=		LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"
USE_XORG=		x11 ice xineramaproto xinerama xrandr xtst
USE_GNOME=		gtk20
PLIST_SUB+=		X11=""
CONFLICTS=		open-vm-tools-nox11-[0-9]*
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

PLIST_SUB+=	LIB32DIR=${LIB32DIR}

SUB_LIST+=	LIB32DIR=${LIB32DIR}

post-patch:
.if defined(WITHOUT_X11)
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/optpatch-nox11
.endif

post-build:
	(cd ${WRKSRC}/modules && ${MAKE})

post-install:
	${MKDIR} ${PREFIX}/${LIB32DIR}/vmware-tools/modules/drivers
	${MKDIR} ${PREFIX}/${LIB32DIR}/vmware-tools/modules/input
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmmemctl.ko ${PREFIX}/${LIB32DIR}/vmware-tools/modules/drivers/vmmemctl.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmxnet.ko ${PREFIX}/${LIB32DIR}/vmware-tools/modules/drivers/vmxnet.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmhgfs.ko ${PREFIX}/${LIB32DIR}/vmware-tools/modules/drivers/vmhgfs.ko
	${INSTALL_DATA} ${WRKSRC}/modules/freebsd/vmblock.ko ${PREFIX}/${LIB32DIR}/vmware-tools/modules/drivers/vmblock.ko
	@-kldxref ${PREFIX}/${LIB32DIR}/vmware-tools/modules/drivers 2>/dev/null
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
