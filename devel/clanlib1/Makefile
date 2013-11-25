# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clanlib
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-1.0/
DISTNAME=	ClanLib-${PORTVERSION}
PKGNAMESUFFIX=	1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform game SDK

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libmikmod.so:${PORTSDIR}/audio/libmikmod \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

USE_AUTOTOOLS=	libtool
USE_XORG=	x11 xi
USES=		gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_SDL=	gfx
USE_GL=		yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs \
		--enable-clanDisplay \
		--enable-clanGL \
		--enable-clanSDL \
		--enable-clanSound \
		--enable-clanNetwork \
		--enable-clanGUI \
		--enable-clanMikMod \
		--enable-clanVorbis \
		--enable-getaddr

PLIST_SUB+=	VER=${PORTVERSION:R}

NO_STAGE=	yes
post-patch:
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|@perl_exec@|${PERL}|g' \
		${WRKSRC}/Documentation/Utilities/webbuilder.pl.in

.include <bsd.port.mk>
