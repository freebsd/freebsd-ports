# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	codeblocks
PORTVERSION=	17.12
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lbartoletti@tuxfamily.org
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
USE_WX=		2.8
USE_GNOME=	gtk20 cairo
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG} --with-contrib-plugins=all \
		--disable-pch --with-boost-system=boost_system
PKG_CONFIG_LIBDIR=	${LOCALBASE}/libdata/pkgconfig
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
USE_CXXSTD=	c++11
. if ${COMPILER_VERSION} >= 35
CXXFLAGS+=	-Wno-undefined-bool-conversion
. endif
.endif

.include <bsd.port.post.mk>
