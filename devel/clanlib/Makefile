# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clanlib
PORTVERSION=	2.3.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-2.0/
DISTNAME=	ClanLib-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Cross-platform game SDK

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		mikmod:${PORTSDIR}/audio/libmikmod \
		vorbis:${PORTSDIR}/audio/libvorbis \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		pcre:${PORTSDIR}/devel/pcre \
		execinfo:${PORTSDIR}/devel/libexecinfo

USE_GCC=	yes
USE_XORG=	x11
USES=		gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GL=		yes
USE_SQLITE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
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

PLIST_SUB+=	VER=${PORTVERSION:R} \
		SHORT_VER=${PORTVERSION:R:R}${PORTVERSION:R:E}

NO_STAGE=	yes
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
