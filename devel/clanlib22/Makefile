# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clanlib
PORTVERSION=	2.2.12
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-2.0/
PKGNAMESUFFIX=	22
DISTNAME=	ClanLib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform game SDK

LICENSE=	ZLIB

LIB_DEPENDS=	libpng.so:graphics/png \
		libmikmod.so:audio/libmikmod \
		libvorbis.so:audio/libvorbis \
		libfontconfig.so:x11-fonts/fontconfig \
		libpcre.so:devel/pcre

USES=		gmake jpeg libtool pathfix pkgconfig sqlite tar:tgz
USE_XORG=	x11
USE_LDCONFIG=	yes
USE_GL=		yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs \
		--enable-clanDisplay \
		--enable-clanGL \
		--enable-clanGL1 \
		--enable-clanSound \
		--enable-clanDatabase \
		--enable-clanSqlite \
		--enable-clanRegExp \
		--enable-clanNetwork \
		--enable-clanGUI \
		--enable-clanCSSLayout \
		--enable-clanSWRender \
		--enable-clanMikMod \
		--enable-clanVorbis \
		--enable-getaddr

INSTALL_TARGET=	install-strip
PLIST_SUB+=	VER=${PORTVERSION:R} \
		SHORT_VER=${PORTVERSION:R:R}${PORTVERSION:R:E}

BROKEN_aarch64=		Fails to configure: error:  Requires SSE2 Support
BROKEN_sparc64=		Fails to configure: error:  Requires SSE2 Support

post-patch:
	@${REINPLACE_CMD} -e '/^extra_LIBS_clanSqlite/s|-ldl||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
