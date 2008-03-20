# New ports collection makefile for:	devel/libdlna
# Date created:				Sat Feb  9 20:20:00 UTC 2008
# Whom:	      				Dave Grochowski <malus.x@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libdlna
PORTVERSION=	0.2.3
CATEGORIES=	devel
MASTER_SITES=	http://libdlna.geexbox.org/releases/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/

MAINTAINER=	malus.x@gmail.com
COMMENT=	Reference DLNA open-source implementation

LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		avformat:${PORTSDIR}/multimedia/ffmpeg

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--prefix="${PREFIX}" --disable-optimize
CONFIGURE_ENV+=		LDFLAGS=-L${LOCALBASE}/lib

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e \
		's#\(PKGCONFIG_DIR = \).*#\1${LOCALBASE}/libdata/pkgconfig#' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
