# New ports collection makefile for:    xplanet
# Date created:		22 Feb 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	xplanet
PORTVERSION=	1.1.0
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	Draw pictures of the earth textured by an image

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-map-extension=jpg
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lm"

PLIST_FILES=	bin/xplanet
MAN1=	xplanet.1

.if !defined(WITHOUT_FREETYPE)
CONFIGURE_ARGS+=	--with-freetype
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if !defined(WITHOUT_PANGO)
CONFIGURE_ARGS+=	--with-pango
USE_GNOME+=	pango
.else
CONFIGURE_ARGS+=	--without-pango
.endif

.if !defined(WITHOUT_GIF)
CONFIGURE_ARGS+=	--with-gif
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
.else
CONFIGURE_ARGS+=	--without-gif
.endif

.if !defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--with-jpeg
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif

.if !defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--with-png
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if !defined(WITHOUT_PNM)
CONFIGURE_ARGS+=	--with-pnm
LIB_DEPENDS+=	netpbm.1:${PORTSDIR}/graphics/netpbm
.else
CONFIGURE_ARGS+=	--without-pnm
.endif

.if !defined(WITHOUT_TIFF)
CONFIGURE_ARGS+=	--with-tiff
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

post-install:
.for file in freebsd.committers.markers freebsd.ftp.markers
	@${INSTALL_DATA} ${PORTSDIR}/astro/xearth/files/${file} \
		${DATADIR}/markers
.endfor
	@${FIND} ${DATADIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
