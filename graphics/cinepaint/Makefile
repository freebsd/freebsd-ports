# New ports collection makefile for:	cinepaint
# Date created:				11 Oct 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	cinepaint
PORTVERSION=	0.20
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	dyeske@yahoo.com
COMMENT=	An editing tool used for painting and retouching of movies

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		lcms.1:${PORTSDIR}/graphics/lcms \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes

MAN1=		cinepaint.1 cinepainttool.1

PLIST_SUB=	VER=${PORTVERSION}-1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-1

.if !defined(WITHOUT_OPENEXR)
LIB_DEPENDS+=	IlmImf.2:${PORTSDIR}/graphics/OpenEXR \
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

.include <bsd.port.mk>
