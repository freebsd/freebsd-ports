# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clanlib
PORTVERSION=	2.2.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-2.0/
DISTNAME=	ClanLib-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform game SDK

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		mikmod:${PORTSDIR}/audio/libmikmod \
		vorbis:${PORTSDIR}/audio/libvorbis \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		pcre:${PORTSDIR}/devel/pcre

LATEST_LINK=	${PORTNAME}22

USE_GMAKE=	yes
USE_XORG=	x11
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_GL=		yes
USE_PKGCONFIG=	yes
USE_SQLITE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15 ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
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

post-patch:
	@${REINPLACE_CMD} -e '/^extra_LIBS_clanSqlite/s|-ldl||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
