# ex:ts=8
# Ports collection Makefile for:	ale
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ale
PORTVERSION=	0.8.11.2
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://auricle.dyndns.org/ALE/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-Lamenessing Engine

OPTIONS=	DOUBLE "64bit Data Precision Support" off \
		FFTW3 "FFTW3 Support" on \
		IMAGEMAGICK "ImageMagick Support" on

USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-assertions

MAN1=		ale.1
PLIST_FILES=	bin/ale bin/ale-bin

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not build on alpha
.endif

.if defined(WITH_DOUBLE)
CONFIGURE_ARGS+=	--with-colors=double --with-coords=double
.endif

.if defined(WITHOUT_FFTW3)
CONFIGURE_ARGS+=	--without-fftw3
.else
LIB_DEPENDS+=	fftw3.5:${PORTSDIR}/math/fftw3
.endif

.if defined(WITHOUT_IMAGEMAGICK)
CONFIGURE_ARGS+=	--without-imagemagick
.else
LIB_DEPENDS+=	MagickWand.4:${PORTSDIR}/graphics/ImageMagick
.endif

.include <bsd.port.post.mk>
