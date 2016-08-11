# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	mp3splt
PORTVERSION=	2.6.2
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Utility to split MP3 and Ogg files (via CUE sheets)

LICENSE=	GPLv2

LIB_DEPENDS=	libmp3splt.so:audio/libmp3splt \
		libltdl.so:devel/libltdl

USES=		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oggsplt_symlink
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lib/pkgconfig

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
