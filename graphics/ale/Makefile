# ex:ts=8
# Ports collection Makefile for:	ale
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ale
PORTVERSION=	0.8.11.2
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://auricle.dyndns.org/ALE/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-Lamenessing Engine

OPTIONS_DEFINE=	DOUBLE FFTW3 MAGICK
OPTIONS_DEFAULT=	FFTW3 MAGICK
DOUBLE_DESC=	64bit Data Precision Support

USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-assertions

MAN1=		ale.1
PLIST_FILES=	bin/ale bin/ale-bin

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not build on alpha
.endif

.if ${PORT_OPTIONS:MDOUBLE}
CONFIGURE_ARGS+=	--with-colors=double --with-coords=double
.endif

.if ${PORT_OPTIONS:MFFTW3}
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
.else
CONFIGURE_ARGS+=	--without-fftw3
.endif

.if ${PORT_OPTIONS:MMAGICK}
LIB_DEPENDS+=	MagickWand.5:${PORTSDIR}/graphics/ImageMagick
.else
CONFIGURE_ARGS+=	--without-imagemagick
.endif

.include <bsd.port.post.mk>
