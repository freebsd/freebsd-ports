# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	dumb
PORTVERSION=	0.9.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	IT, XM, S3M, and MOD player library

USES=		gmake

OPTIONS_DEFINE=	ALLEGRO
OPTIONS_SUB=	yes
ALLEGRO_DESC=	Enable allegro support

ALLEGRO_LIB_DEPENDS=	liballeg.so:devel/allegro
ALLEGRO_MAKE_ARGS=	_PORT_ALLEGRO_CFLAGS="`allegro-config --cflags`" \
			LINK_ALLEGRO="`allegro-config --libs` -lm"
ALLEGRO_CONFLICTS=	dumb-[0-9]*
ALLEGRO_MAKE_ARGS_OFF=	_PORT_ALLEGRO_CFLAGS=
ALLEGRO_CONFLICTS_OFF=	dumb-allegro-[0-9]*

# libdumb.a is linked into libaudiere.so from audio/audiere.
CFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e 's|_INSTALL_PATH := |&$${DESTDIR}|' ${WRKSRC}/Makefile

do-configure:
	@${ECHO_CMD} 'include make/unix.inc' > ${WRKSRC}/make/config.txt
	@${ECHO_CMD} 'ALL_TARGETS := core core-examples core-headers' >> ${WRKSRC}/make/config.txt
do-configure-ALLEGRO-on:
	@${ECHO_CMD} 'ALL_TARGETS += allegro allegro-examples allegro-headers' >> ${WRKSRC}/make/config.txt

.include <bsd.port.mk>
