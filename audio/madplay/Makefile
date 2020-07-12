# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	madplay
PORTVERSION=	0.15.2b
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SF/mad/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Madplay MP3 player (part of MAD project)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libmad.so:audio/libmad \
		libid3tag.so:audio/libid3tag

USES=		localbase

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-esd
LDFLAGS+=	-lz
ALL_TARGET=	all madtime

OPTIONS_DEFINE=	NLS SNDIO
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

SNDIO_CONFIGURE_WITH=	sndio
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

post-extract-SNDIO-on:
	@${CP} ${FILESDIR}/audio_sndio.c ${WRKSRC}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/madtime ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
