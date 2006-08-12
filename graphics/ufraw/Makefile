# New ports collection makefile for:	UFRaw
# Date created:				Sun 10 Apr 2005 14:44:15 BST
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		ufraw
PORTVERSION=		0.9.1
CATEGORIES=		graphics gnome
MASTER_SITES=		SF

MAINTAINER=		infofarmer@FreeBSD.org
COMMENT=		Read and manipulate raw images from digital cameras

BUILD_DEPENDS=		gimp:${PORTSDIR}/graphics/gimp
LIB_DEPENDS=		jpeg.9:${PORTSDIR}/graphics/jpeg \
			tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=		${BUILD_DEPENDS}

GNU_CONFIGURE=		yes
USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_GNOME=		glib20 gnomehack intltool intlhack gtk20 libartlgpl2
WANT_GNOME=		yes

CONFIGURE_ENV=		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
			CFLAGS="${CFLAGS} -I ${LOCALBASE}/include"
CONFIGURE_ARGS=		--mandir=${MANPREFIX}/man

.ifndef WITHOUT_EXIF
LIB_DEPENDS+=		exif:${PORTSDIR}/graphics/libexif
CONFIGURE_ARGS+=	--with-libexif
.ifndef WITHOUT_EXIV2
LIB_DEPENDS+=		exiv2:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=	--with-exiv2
.endif
.endif

MAN1=			ufraw.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 504105
BROKEN=		Needs memmem(3)
.endif

.include <bsd.port.post.mk>
