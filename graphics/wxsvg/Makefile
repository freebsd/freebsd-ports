# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wxsvg
PORTVERSION=	1.1.15
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to create, manipulate, and render SVG files

LICENSE=	LGPL21 # (or later)

LIB_DEPENDS=	avcodec1:${PORTSDIR}/multimedia/ffmpeg1 \
		expat:${PORTSDIR}/textproc/expat2

USE_BZIP2=	yes
USES=		pathfix pkgconfig
USE_WX=		yes
WX_CONF_ARGS=	absolute
USE_GNOME=	cairo
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBAV_CFLAGS="${LIBAV_CFLAGS}" LIBAV_LIBS="${LIBAV_LIBS}"
MAKE_ENV=	AM_CPPFLAGS="${LIBAV_CFLAGS}"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LIBAV_PC=	libavcodec1 libavformat1 libavutil1 libswscale1
LIBAV_CFLAGS=	$$(pkg-config --cflags ${LIBAV_PC})
LIBAV_LIBS=	$$(pkg-config --libs ${LIBAV_PC})

post-extract:
.for i in configure install-sh
	@${CHMOD} ${BINMODE} ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
