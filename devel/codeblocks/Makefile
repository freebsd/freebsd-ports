PORTNAME=	codeblocks
PORTVERSION=	20.03
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Open source, cross-platform, free C/C++ IDE

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libhunspell-1.7.so:textproc/hunspell \
		libtinyxml.so:textproc/tinyxml

USES=		autoreconf compiler:c++11-lang desktop-file-utils \
		fam:gamin gettext-runtime gnome libtool localbase \
		pathfix pkgconfig shared-mime-info tar:xz xorg
USE_WX=		3.0+
USE_GNOME=	gtk30 cairo
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG} --disable-pch \
		--with-boost-system=boost_system
PKG_CONFIG_LIBDIR=	${LOCALBASE}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CONFIGURE_ARGS+=	--with-contrib-plugins=all,-dragscroll
PLIST_SUB=	X86="@comment "
.else
CONFIGURE_ARGS+=	--with-contrib-plugins=all
PLIST_SUB=	X86=""
.endif

.include <bsd.port.post.mk>
