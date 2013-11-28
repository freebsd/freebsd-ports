# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clanlib
PORTVERSION=	2.2.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-2.0/
DISTNAME=	ClanLib-${PORTVERSION}
PKGNAMESUFFIX=	22
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform game SDK

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libmikmod.so:${PORTSDIR}/audio/libmikmod \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpcre.so:${PORTSDIR}/devel/pcre

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
	@${REINPLACE_CMD} -e '/^extra_LIBS_clanSqlite/s|-ldl||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
