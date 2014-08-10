# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	dumb
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	IT, XM, S3M, and MOD player library

USES=		gmake

OPTIONS_DEFINE=	ALLEGRO
ALLEGRO_DESC=	Enable allegro support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALLEGRO}
LIB_DEPENDS+=	liballeg.so:${PORTSDIR}/devel/allegro
PLIST_SUB+=	ALLEGRO=""
MAKE_ARGS=	_PORT_ALLEGRO_CFLAGS="`allegro-config --cflags`"
MAKE_ARGS+=	LINK_ALLEGRO="`allegro-config --libs` -lm"
PKGNAMESUFFIX=	-allegro
CONFLICTS=	dumb-[0-9]*
.else
PLIST_SUB+=	ALLEGRO="@comment "
MAKE_ARGS=	_PORT_ALLEGRO_CFLAGS=
CONFLICTS=	dumb-allegro-[0-9]*
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|_INSTALL_PATH := |&$${DESTDIR}|' ${WRKSRC}/Makefile

do-configure:
	@${ECHO_CMD} 'include make/unix.inc' > ${WRKSRC}/make/config.txt
	@${ECHO_CMD} 'ALL_TARGETS := core core-examples core-headers' >> ${WRKSRC}/make/config.txt
.if ${PORT_OPTIONS:MALLEGRO}
	@${ECHO_CMD} 'ALL_TARGETS += allegro allegro-examples allegro-headers' >> ${WRKSRC}/make/config.txt
.endif

.include <bsd.port.mk>
