# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	madplay
PORTVERSION=	0.15.2b
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/mad/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Madplay MP3 player (part of MAD project)

LICENSE=	GPLv2

LIB_DEPENDS=	libmad.so:audio/libmad \
		libid3tag.so:audio/libid3tag

USES=		localbase

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-esd
LDFLAGS+=	-lz
ALL_TARGET=	all madtime

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/madtime ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
