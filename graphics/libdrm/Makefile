# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	${LIBDRM_VERSION}
PORTREVISION=	${LIBDRM_REVISION}
PORTEPOCH=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

LIB_DEPENDS=	libpciaccess.so:${PORTSDIR}/devel/libpciaccess \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pkgconfig tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MANPAGES

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	MANPAGES
.endif

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)

USES+=		gmake

# KMS support in the kernel is only build on these archs, disable others
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
CONFIGURE_ARGS+=--enable-libkms
EXTRA_PATCHES+=	${FILESDIR}/extra-xf86drmMode.c
PLIST_SUB+=	KMS="" NOUVEAU=""
.else
CONFIGURE_ARGS+=--disable-libkms
PLIST_SUB+=	KMS="@comment " NOUVEAU="@comment "
.endif

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
USE_GNOME+=	libxslt:build
PLIST_SUB+=	MAN=""
.else
CONFIGURE_ARGS+=--disable-manpages
PLIST_SUB+=	MAN="@comment "
.endif

LIBDRM_VERSION=	2.4.52
LIBDRM_REVISION=1
PLIST_SUB+=	OLD="@comment " NEW=""
EXTRA_PATCHES+=	${FILESDIR}/extra-configure \
		${FILESDIR}/extra-tests_modetest_Makefile.in \
		${FILESDIR}/extra-tests_modetest_modetest.c \
		${FILESDIR}/extra-tests_modetest_strchrnul.c \
		${FILESDIR}/extra-tests__radeon__radeon_ttm.c
CONFIGURE_ARGS+=--disable-vmwgfx
.else
CONFIGURE_ARGS=	--enable-nouveau-experimental-api
LIBDRM_VERSION=	2.4.17
LIBDRM_REVISION=2
PLIST_SUB+=	OLD="" NEW="@comment " NOUVEAU=""
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	INTEL_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
.elif ${ARCH} == ia64 || ${ARCH} == powerpc || ${ARCH} == powerpc64
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
.else
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g; \
			   s,i?86|x86_64),i?86|amd64|x86_64),g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
