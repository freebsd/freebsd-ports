# New ports collection makefile for:	cinepaint
# Date created:				11 Oct 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	cinepaint
PORTVERSION=	0.18
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	dyeske@yahoo.com
COMMENT=	An editing tool used for painting and retouching of movies

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=13
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

MAN1=		cinepaint.1 cinepainttool.1

PLIST_SUB=	VER=${PORTVERSION}-1

.if !defined(WITHOUT_OPENEXR)
LIB_DEPENDS+=	IlmImf.2:${PORTSDIR}/graphics/OpenEXR
CONFIGURE_ARGS+=	--with-openexr-prefix=${LOCALBASE}
PLIST_SUB+=	OPENEXR:=""
.else
PLIST_SUB+=	OPENEXR:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| -Wall||' \
		${WRKSRC}/configure

	@${REINPLACE_CMD} -E -e \
		's|-LINUX.+$$||' \
		${WRKSRC}/Makefile.in

	@${REINPLACE_CMD} -e \
		's|static GDrawableType|static GImageType|' \
		${WRKSRC}/plug-ins/psd/psd.c

.include <bsd.port.mk>
