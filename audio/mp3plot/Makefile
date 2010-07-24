# New ports collection makefile for:	mp3plot
# Date created:		12 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mp3plot
DISTVERSION=	0.6.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://p.outlyer.net/mp3plot/files/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Mp3 bitrate plot tool

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

OPTIONS=	GD "Enable support for GD library" on \
		IMAGEMAGICK "Enable support for Magick++" off

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-boost-program-options=boost_program_options \
		--with-boost-thread=boost_thread

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

.if defined(WITHOUT_GD)
CONFIGURE_ARGS+=	--disable-gd
.else
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
.endif

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	Magick++.4:${PORTSDIR}/graphics/ImageMagick
.else
CONFIGURE_ARGS+=	--disable-magick
.endif

post-patch:
	@${REINPLACE_CMD} -e '/bldtype_/s|-O2||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
