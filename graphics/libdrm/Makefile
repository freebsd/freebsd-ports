# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	2.4.65
PORTEPOCH=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

LIB_DEPENDS=	libpciaccess.so:${PORTSDIR}/devel/libpciaccess \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

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

CONFIGURE_ARGS+=--disable-vmwgfx

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
