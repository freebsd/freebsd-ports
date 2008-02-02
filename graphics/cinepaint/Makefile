# New ports collection makefile for:	cinepaint
# Date created:				11 Oct 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cinepaint
PORTVERSION=	0.22
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	dyeske@gmail.com
COMMENT=	An editing tool used for painting and retouching of movies

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		lcms.1:${PORTSDIR}/graphics/lcms \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	gtk12
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

MAN1=		cinepaint.1 cinepainttool.1

PLIST_SUB=	VER=${PORTVERSION}-1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-1

OPTIONS=	OPENEXR "Use OpenEXR" on

.include <bsd.port.pre.mk>

.if defined(WITH_OPENEXR)
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads
CONFIGURE_ARGS+=	--with-openexr-prefix=${LOCALBASE}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include/OpenEXR"
PLIST_SUB+=	OPENEXR:=""
.else
PLIST_SUB+=	OPENEXR:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| -Wall||' \
		${WRKSRC}/configure

	@${REINPLACE_CMD} -E -e \
		's|-LINUX.+$$|| ; s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

	@${REINPLACE_CMD} -e \
		's|static GDrawableType|static GImageType|' \
		${WRKSRC}/plug-ins/psd/psd.c

.include <bsd.port.post.mk>
