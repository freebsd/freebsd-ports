# New ports collection makefile for:	imlib2
# Date created:		16 Oct 2000
# Whom:			>Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/e17/libs/ \
		http://www.us.rasterman.com/files/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		edb.1:${PORTSDIR}/databases/edb

USE_X_PREFIX=	yes
USE_FREETYPE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS=	--enable-mmx
.endif

post-install:
	strip ${PREFIX}/lib/libImlib2.so.1
	strip ${PREFIX}/lib/loaders/filter/*
	strip ${PREFIX}/lib/loaders/image/*
.include <bsd.port.post.mk>
