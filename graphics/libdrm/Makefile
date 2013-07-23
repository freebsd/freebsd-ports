# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	${LIBDRM_VERSION}
PORTREVISION=	${LIBDRM_REVISION}
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

LIB_DEPENDS=	pciaccess:${PORTSDIR}/devel/libpciaccess \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

.if defined(WITH_NEW_XORG)

USE_GMAKE=	yes

OPTIONS_DEFINE=	KMS MANPAGES
OPTIONS_DEFAULT=KMS
KMS_DESC=	Enable KMS support

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	MANPAGES
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKMS}
CONFIGURE_ARGS+=--enable-libkms
EXTRA_PATCHES+=	${FILESDIR}/extra-xf86drmMode.c
PLIST_SUB+=	KMS=""
.else
PLIST_SUB+=	KMS="@comment "
.endif

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt
MAN3=		drmAvailable.3 \
		drmHandleEvent.3 \
		drmModeGetResources.3
MAN7=		drm-gem.7 \
		drm-kms.7 \
		drm-memory.7 \
		drm-mm.7 \
		drm-ttm.7 \
		drm.7
.else
CONFIGURE_ARGS+=--disable-manpages
.endif

LIBDRM_VERSION=	2.4.46
LIBDRM_REVISION=0
PLIST_SUB+=	OLD="@comment " NEW=""
EXTRA_PATCHES+=	${FILESDIR}/extra-configure \
		${FILESDIR}/extra-tests_modetest_Makefile.in \
		${FILESDIR}/extra-tests_modetest_modetest.c \
		${FILESDIR}/extra-tests_modetest_strchrnul.c
CONFIGURE_ARGS+=--disable-vmwgfx
.else
CONFIGURE_ARGS=	--enable-nouveau-experimental-api
LIBDRM_VERSION=	2.4.17
LIBDRM_REVISION=1
PLIST_SUB+=	OLD="" NEW="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64" || ${ARCH} == "powerpc"
PLIST_SUB+=	INTEL_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
.else
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g; \
			   s,i?86|x86_64),i?86|amd64|x86_64),g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
