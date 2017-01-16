# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	2.4.74
PORTEPOCH=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

LICENSE=	MIT

BUILD_DEPENDS=	libdevq>=0.0.4:devel/libdevq
LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess \
		libdevq.so:devel/libdevq \
		libpthread-stubs.so:devel/libpthread-stubs

USES=		libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MANPAGES

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	MANPAGES
.endif

USES+=		gmake

.include <bsd.port.options.mk>

# KMS support in the kernel is only build on these archs, disable others
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
CONFIGURE_ARGS+=--enable-libkms
PLIST_SUB+=	KMS=""
.else
CONFIGURE_ARGS+=--disable-libkms
PLIST_SUB+=	KMS="@comment "
.endif

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
USE_GNOME+=	libxslt:build
PLIST_SUB+=	MAN=""
.else
CONFIGURE_ARGS+=--disable-manpages
PLIST_SUB+=	MAN="@comment "
.endif

CONFIGURE_ARGS+=--disable-vmwgfx

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	ARM_DRIVERS="@comment "
PLIST_SUB+=	INTEL_DRIVER=""
PLIST_SUB+=	NOUVEAU_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
.elif ${ARCH} == powerpc || ${ARCH} == powerpc64
PLIST_SUB+=	ARM_DRIVERS="@comment "
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
.elif ${ARCH} == arm6 || ${ARCH} == aarch64
PLIST_SUB+=	ARM_DRIVERS=""
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
.else
PLIST_SUB+=	ARM_DRIVERS="@comment "
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
.endif

# This variable is not for users. So use a non-default name, intended for
# people working on DRM kernel module development.
.if !defined(LIBDRM_SKIP_RETURN_PATCH)
EXTRA_PATCHES+=	${FILESDIR}/extra-xf86drm.c
.endif

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g; \
			   s,i?86|x86_64),i?86|amd64|x86_64),g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
