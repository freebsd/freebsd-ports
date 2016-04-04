# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	madplay
PORTVERSION=	0.15.2b
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/mad/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Madplay MP3 player (part of MAD project)

LICENSE=	GPLv2

LIB_DEPENDS=	libmad.so:audio/libmad \
		libid3tag.so:audio/libid3tag

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lz
ALL_TARGET=	all madtime

OPTIONS_DEFINE=	NLS ESOUND
OPTIONS_DEFAULT=ESOUND
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
ESOUND_USE=		GNOME=esound
ESOUND_CONFIGURE_WITH=	esd

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/madtime ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
