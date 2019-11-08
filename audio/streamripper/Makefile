# Created by: trevor
# $FreeBSD$

PORTNAME=	streamripper
PORTVERSION=	1.64.6
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28current%29/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsdports@xorcara.com
COMMENT=	Splits SHOUTcast stream into tracks

LICENSE=	GPLv2

LIB_DEPENDS=	libmad.so:audio/libmad \
		libtre.so:textproc/libtre \
		libcdk.so:devel/cdk

OPTIONS_DEFINE=	FAAD VORBIS
OPTIONS_DEFAULT=FAAD VORBIS

USES=		gnome iconv ncurses pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-libmad \
		--without-included-tre \
		--with-included-argv \
		--with-included-cdk

PLIST_FILES=	bin/streamripper \
		man/man1/streamripper.1.gz

CFLAGS+=	-DANSI_PROTOTYPES
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

FAAD_CONFIGURE_OFF=	ac_cv_lib_faad_NeAACDecDecode2=no
FAAD_LIB_DEPENDS=	libfaad.so:audio/faad

VORBIS_CONFIGURE_WITH=	ogg=${LOCALBASE}
VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamripper ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/streamripper.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
