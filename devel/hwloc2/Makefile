PORTNAME=	hwloc
DISTVERSION=	2.12.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.open-mpi.org/release/hwloc/v${DISTVERSION:R}/
PKGNAMESUFFIX=	2

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Portable Hardware Locality software package
WWW=		https://www.open-mpi.org/projects/hwloc/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess

USES=		cpe gnome iconv libtool pathfix pkgconfig tar:bzip2
CPE_VENDOR=	open-mpi
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cuda \
		--disable-gl \
		--disable-opencl \
		--disable-nvml \
		--enable-static

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFLICTS_INSTALL=	hwloc

PORTDOCS=	*

OPTIONS_DEFINE=		CAIRO DEBUG DOCS L0
OPTIONS_DEFAULT=	L0
OPTIONS_SUB=		yes

L0_DESC=		oneAPI Level Zero device discovery

CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_USES=		xorg
CAIRO_USE=		XORG=x11
CAIRO_CONFIGURE_ON=	--enable-cairo --with-x
CAIRO_CONFIGURE_OFF=	--disable-cairo --without-x

# 'lstopo -' prints a lot of debug details when debug is enabled,
# this is separate from WITH_DEBUG=yes
DEBUG_CONFIGURE_ENABLE=	debug

L0_LIB_DEPENDS=		libze_loader.so:devel/level-zero
L0_CONFIGURE_ENABLE=	levelzero

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
PLIST_SUB+=	X86="@comment "
.else
PLIST_SUB+=	X86=""
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/doxygen-doc/html/* \
		${STAGEDIR}${DOCSDIR}/html/

.include <bsd.port.post.mk>
