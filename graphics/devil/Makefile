# New ports collection makefile for:   devil
# Date created:        8 August 2004
# Whom:                Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	devil
PORTVERSION=	1.7.0
CATEGORIES=	graphics
MASTER_SITES=	SF/openil
DISTNAME=	DevIL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full featured cross-platform image library

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		mng.1:${PORTSDIR}/graphics/libmng \
		lcms.1:${PORTSDIR}/graphics/lcms

OPTIONS=	SDL "Enable SDL support" off

NO_WRKSUBDIR=	yes

USE_GL=		glu
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262 libtool:15
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --force-missing
CONFIGURE_ARGS=	--disable-allegro --disable-directx8 --disable-directx9 \
		--disable-altivec --disable-sse --disable-sse2 --disable-sse3

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_SDL)
USE_SDL=	yes
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/configure.ac

.include <bsd.port.post.mk>
