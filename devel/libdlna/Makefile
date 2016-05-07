# Created by: Dave Grochowski <malus.x@gmail.com>
# $FreeBSD$

PORTNAME=	libdlna
PORTVERSION=	0.2.3
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://libdlna.geexbox.org/releases/ \
		LOCAL/ehaupt

MAINTAINER=	malus.x@gmail.com
COMMENT=	Reference DLNA open-source implementation

LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg

HAS_CONFIGURE=	yes
USES=		tar:bzip2 gmake pkgconfig
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-optimize \
		--includedir="${PREFIX}/include" \
		--libdir="${PREFIX}/lib"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's#\(PKGCONFIG_DIR = \).*#\1${STAGEDIR}${PREFIX}/libdata/pkgconfig#' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
