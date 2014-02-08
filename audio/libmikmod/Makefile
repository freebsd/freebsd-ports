# Created by: Michael Haro <mharo@area51.fremont.ca.us>
# $FreeBSD$

PORTNAME=	libmikmod
PORTVERSION=	3.1.12
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/mikmod/libmikmod%20%28source%29/${PORTVERSION}/

MAINTAINER=	neuroworker@gmail.com
COMMENT=	MikMod Sound Library

WANT_GNOME=	yes
USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--disable-esd
USE_LDCONFIG=	yes

INFO=		mikmod

post-extract:
	@${RM} -f ${WRKSRC}/docs/mikmod.info-*

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\$$CFLAGS -pthread|\$$CFLAGS ${PTHREAD_CFLAGS}|g' \
		-e 's|-pthread \$$REENTRANT|\$$REENTRANT ${PTHREAD_CFLAGS}|g' \
		-e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|-pthread|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|-lc_r|${PTHREAD_LIBS:S/"//g}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
