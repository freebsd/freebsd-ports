# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	2.4.83
PORTEPOCH=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess

USES=		libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MANPAGES TESTS
OPTIONS_SUB=	yes

TESTS_DESC=	Install test programs (which are always built)

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	MANPAGES
.endif

MANPAGES_CONFIGURE_ENABLE=	manpages
MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
MANPAGES_USE=		GNOME=libxslt:build

TESTS_CONFIGURE_ENABLE=	install-test-programs

# avoid circular dependency in case cairo supports OpenGL (cairo->mesa-libs->libdrm->cairo)
CONFIGURE_ARGS+=	--disable-cairo-tests

.include <bsd.port.options.mk>

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
.elif ${ARCH} == armv6 || ${ARCH} == aarch64
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
.if ${OPSYS} == FreeBSD && !defined(LIBDRM_SKIP_RETURN_PATCH)
EXTRA_PATCHES+=	${FILESDIR}/extra-xf86drm.c
.endif

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g; \
			   s,i?86|x86_64),i?86|amd64|x86_64),g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
