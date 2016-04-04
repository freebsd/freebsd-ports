# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clanlib
PORTVERSION=	2.3.7
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-2.0/
DISTNAME=	ClanLib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform game SDK

LICENSE=	ZLIB

LIB_DEPENDS=	libpng.so:graphics/png \
		libmikmod.so:audio/libmikmod \
		libvorbis.so:audio/libvorbis \
		libfontconfig.so:x11-fonts/fontconfig \
		libpcre.so:devel/pcre

USES=		execinfo gmake jpeg libtool pathfix pkgconfig sqlite tar:tgz
USE_GCC=	yes
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

post-patch:
	@${REINPLACE_CMD} -e 's|LIBS="-lsqlite3 -ldl"|LIBS="-lsqlite3"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '114 s|/proc/self/exe|/proc/curproc/file|g' \
		${WRKSRC}/Sources/Core/System/Unix/init_linux.cpp
	@${REINPLACE_CMD} -e 's|APPLE|FreeBSD|g' \
		${WRKSRC}/Sources/Core/System/system.cpp
	@${REINPLACE_CMD} -e '47 s|#ifndef __FreeBSD__|#if !defined(__FreeBSD__)|g' \
		${WRKSRC}/Sources/Core/System/system.cpp

.include <bsd.port.mk>
