# $FreeBSD$

PORTNAME=	liborcus
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	devel misc
MASTER_SITES=	http://kohei.us/files/orcus/src/
PKGNAMESUFFIX=	07

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/mdds/global.hpp:devel/mdds0
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

DEPRECATED=	Deprecated by upstream, use devel/liborcus
EXPIRATION_DATE=	2017-03-31

BROKEN_sparc64=	cannot link with boost

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-spreadsheet-model --disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
