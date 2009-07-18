# New ports collection makefile for:	imlib2
# Date created:		16 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	1.4.1.000
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	The next generation graphics library for Enlightenment

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

OPTIONS=	JPEG	"Enable jpeg image support"	on \
		PNG	"Enable png image support"	on \
		TIFF	"Enable tiff image support"	on \
		GIF	"Enable GIF image support"	on \
		ID3	"Enable IDv3 tags support"	on \
		X11	"Enable X11 support"		on

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-mmx
.endif

.if (${ARCH} == "amd64")
CONFIGURE_ARGS+=	--enable-amd64
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PKGNAMESUFFIX+=	-nox11
PLIST_SUB=	X11="@comment "
.else
USE_XORG=	x11 sm xext
PLIST_SUB=	X11=""
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=	--without-jpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=	PNG="@comment "
.endif

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=	--without-tiff
PLIST_SUB+=	TIFF="@comment "
.endif

.if !defined(WITHOUT_GIF)
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
PLIST_SUB+=	GIF=""
.else
CONFIGURE_ARGS+=	--without-gif
PLIST_SUB+=	GIF="@comment "
.endif

.if !defined(WITHOUT_ID3)
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag
PLIST_SUB+=	ID3=""
.else
CONFIGURE_ARGS+=	--without-id3
PLIST_SUB+=	ID3="@comment "
.endif

.include <bsd.port.post.mk>
