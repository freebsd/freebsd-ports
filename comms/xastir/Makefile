# New ports collection makefile for:	xastir
# Date created:				17th June 2004
# Whom:					Carl Makin <carl@stagecraft.cx>
#
# $FreeBSD$
#

PORTNAME=	xastir
PORTVERSION=	1.4.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xastir

MAINTAINER=	carl@stagecraft.cx
COMMENT=	X Amateur Station Tracking and Information Reporting

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes

MAN1=		xastir.1

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	SHAPELIB "Include Shapelib support" On \
		PCRE "Include Perl Compatible Regular Expression Support" On \
		DBFAWK "Include DBFAWK Support" On \
		MAGICK "Include ImageMagick Support" On \
		CURL "Include CURL Internet Image support" On \
		GDAL "Include GDAL Support" Off \
		GPSMAN "Include GPSMAN Support" Off \
		FESTIVAL "Include Festival Voice Synthesis Support" Off \
		OPTCFLAGS "Use optimized CFLAGS (-O2 -pipe)" Off

.include <bsd.port.pre.mk>

.if defined(WITH_FESTIVAL)
RUN_DEPENDS+=	festival:${PORTSDIR}/audio/festival
.else
CONFIGURE_ARGS+=	--without-festival
.endif

.if defined(WITH_GPSMAN)
RUN_DEPENDS+=	gpsman:${PORTSDIR}/astro/gpsman
WITH_SHAPELIB=	true
.undef WITHOUT_SHAPELIB
.else
CONFIGURE_ARGS+=	--without-gpsman
.endif

.if defined(WITHOUT_SHAPELIB)
CONFIGURE_ARGS+=	--without-shapelib
.else
LIB_DEPENDS+=	shp.1:${PORTSDIR}/devel/shapelib
.endif

.if defined(WITHOUT_MAGICK)
CONFIGURE_ARGS+=	--without-imagemagick
.else
LIB_DEPENDS+=	Magick:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITHOUT_DBFAWK)
CONFIGURE_ARGS+=	--without-dbfawk
WITH_PCRE=	true
.undef WITHOUT_PCRE
.endif

.if defined(WITHOUT_PCRE)
CONFIGURE_ARGS+=	--without-pcre
.else
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.endif

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

.if defined(WITH_GDAL)
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
.else
CONFIGURE_ARGS+=	--without-gdal
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
WITH_OPTCFLAGS=	true
.endif

# OPTIMIZED_CFLAGS is too big for the OPTIONS variable to draw on the screen.
.if defined(WITH_OPTCFLAGS)
CFLAGS+=	-O2 -pipe
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${.CURDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
