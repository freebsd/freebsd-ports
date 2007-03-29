# New ports collection makefile for:	UFRaw
# Date created:				Sun 10 Apr 2005 14:44:15 BST
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ufraw
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Read and manipulate raw images from digital cameras

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		gimpui-2.0:${PORTSDIR}/graphics/gimp \
		lcms.1:${PORTSDIR}/graphics/lcms

GCONF_SCHEMAS=	${PORTNAME}.schemas
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 glib20 gnomehack intltool intlhack libartlgpl2 pkgconfig
WANT_GNOME=	yes

LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man --enable-mime

.ifndef WITHOUT_EXIF
LIB_DEPENDS+=	exif:${PORTSDIR}/graphics/libexif
CONFIGURE_ARGS+=--with-libexif
.ifndef WITHOUT_EXIV2
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--with-exiv2
.endif
.endif

MAN1=	ufraw.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 504105
BROKEN=	Needs memmem(3)
.endif

post-patch:
	@${REINPLACE_CMD} -e '/@schemasdir/s|datadir|sysconfdir|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
