PORTNAME=	mp3splt
PORTVERSION=	2.6.2
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Utility to split MP3 and Ogg files (via CUE sheets)

LICENSE=	GPLv2

BROKEN=		Doesn't run (segmentation fault)
DEPRECATED=	Abandonware, last release in 2014
EXPIRATION_DATE=2022-09-30

LIB_DEPENDS=	libmp3splt.so:audio/libmp3splt \
		libltdl.so:devel/libltdl

USES=		cpe pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oggsplt_symlink

CPE_VENDOR=	mp3splt_project

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
