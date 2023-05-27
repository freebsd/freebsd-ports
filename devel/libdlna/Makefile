PORTNAME=	libdlna
PORTVERSION=	0.2.3
PORTREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	http://libdlna.geexbox.org/releases/ \
		LOCAL/ehaupt

MAINTAINER=	malus.x@gmail.com
COMMENT=	Reference DLNA open-source implementation
WWW=		https://libdlna.geexbox.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandonware, development discontinued
EXPIRATION_DATE=2023-06-30

LIB_DEPENDS=	libavcodec.so.58:multimedia/ffmpeg4

HAS_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig tar:bzip2
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/ffmpeg4/include
LDFLAGS+=	-L${LOCALBASE}/ffmpeg4/lib

CONFIGURE_ARGS=	--with-ffmpeg-dir="${LOCALBASE}/ffmpeg4" \
		--prefix="${PREFIX}" --disable-optimize

post-extract:
	${REINPLACE_CMD} -e 's|CODEC_ID|AV_CODEC_ID|g' \
		${WRKSRC}/src/*.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdlna.so

.include <bsd.port.mk>
