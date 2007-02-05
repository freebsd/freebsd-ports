# ex:ts=8
# Ports collection makefile for:	swftools
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swftools
PORTVERSION=	0.8.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.swftools.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SWF manipulation and generation utilities

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_BISON=	yes
USE_GNOME=	pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
CPPFLAGS=	`pkg-config --cflags-only-I fontconfig freetype2` \
		-I${LOCALBASE}/include
LDFLAGS=	`pkg-config --libs-only-L fontconfig freetype2` \
		-L${LOCALBASE}/lib

MAN1=		font2swf.1 gif2swf.1 jpeg2swf.1 pdf2swf.1 png2swf.1 \
		swfbbox.1 swfc.1 swfcombine.1 swfdump.1 swfextract.1 \
		swfstrings.1 wav2swf.1

.if defined(WITH_LAME) || exists(${LOCALBASE}/lib/libmp3lame.a)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.include <bsd.port.mk>
