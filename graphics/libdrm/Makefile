# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	2.4.98
PORTEPOCH=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess

USES=		gnome meson pkgconfig tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MANPAGES TESTS
OPTIONS_SUB=	yes

TESTS_DESC=	Install test programs (which are always built)

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	MANPAGES
.endif

MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
MANPAGES_USE=		GNOME=libxslt:build
MANPAGES_MESON_TRUE=	man-pages

TESTS_MESON_TRUE=	install-test-programs

# avoid circular dependency in case cairo supports OpenGL (cairo->mesa-libs->libdrm->cairo)
CONFIGURE_ARGS+=	-Dcairo-tests=false

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
.elif ${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7
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

.include <bsd.port.mk>
