# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	codeblocks
PORTVERSION=	16.01
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Open source, cross-platform, free C/C++ IDE

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libhunspell-1.3.so:textproc/hunspell

USES=		autoreconf compiler desktop-file-utils fam:gamin libtool pathfix \
		pkgconfig shared-mime-info
USE_WX=		2.8
WANT_UNICODE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG} --with-contrib-plugins=all \
		--disable-pch
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lboost_system
PKG_CONFIG_LIBDIR=	${LOCALBASE}/libdata/pkgconfig
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.release

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
USE_CXXSTD=	c++11
. if ${COMPILER_VERSION} >= 35
CXXFLAGS+=	-Wno-undefined-bool-conversion
. endif
.endif

.include <bsd.port.post.mk>
