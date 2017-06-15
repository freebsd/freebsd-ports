# Created by: Dave Grochowski <malus.x@gmail.com>
# $FreeBSD$

PORTNAME=	libdlna
PORTVERSION=	0.2.3
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://libdlna.geexbox.org/releases/ \
		LOCAL/ehaupt

MAINTAINER=	malus.x@gmail.com
COMMENT=	Reference DLNA open-source implementation

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

HAS_CONFIGURE=	yes
USES=		gmake localbase pathfix pkgconfig tar:bzip2
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-optimize \
		--includedir="${PREFIX}/include" \
		--libdir="${PREFIX}/lib"

post-extract:
	${REINPLACE_CMD} -e 's|CODEC_ID|AV_CODEC_ID|g' \
		${WRKSRC}/src/*.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdlna.so

.include <bsd.port.mk>
