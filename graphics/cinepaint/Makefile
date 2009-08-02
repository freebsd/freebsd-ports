# New ports collection makefile for:	cinepaint
# Date created:				11 Oct 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cinepaint
PORTVERSION=	0.22
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An editing tool used for painting and retouching of movies

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		lcms.1:${PORTSDIR}/graphics/lcms \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ftgl.2:${PORTSDIR}/graphics/ftgl

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	gtk12
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_XORG=	xpm

MAN1=		cinepaint.1 cinepainttool.1

PLIST_SUB=	VER=${PORTVERSION}-1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-1

OPTIONS=	OPENEXR "Use OpenEXR" on

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_OPENEXR)
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR
BUILD_DEPENDS+=	fltk-threads>0:${PORTSDIR}/x11-toolkits/fltk-threads
RUN_DEPENDS+=	fltk-threads>0:${PORTSDIR}/x11-toolkits/fltk-threads
CONFIGURE_ARGS+=	--with-openexr-prefix=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include/openEXR
PLIST_SUB+=	OPENEXR:=""
.else
PLIST_SUB+=	OPENEXR:="@comment "
.endif

CONFIGURE_ENV+=	CPPFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

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
