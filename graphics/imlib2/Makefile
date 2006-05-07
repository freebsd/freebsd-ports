# New ports collection makefile for:	imlib2
# Date created:		16 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	1.2.2.001
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The next generation graphic library for enlightenment package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		freetype.9:${PORTSDIR}/print/freetype2

USE_AUTOTOOLS=	autoconf:259 libltdl:15 libtool:15
USE_GNOME=	gnomehack pkgconfig gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-mmx
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PKGNAMESUFFIX+=	-nox11
PLIST_SUB=	X11="@comment "
.else
USE_XLIB=	yes
PLIST_SUB=	X11=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|round|rint|g' ${WRKSRC}/src/lib/color_helpers.c

# Kludge to keep it from touching Makefile.in files (configure.in is newer)
post-configure:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${TOUCH}

.include <bsd.port.post.mk>
