# ports collection makefile for:	libmikmod
# Date created:		Sun Apr 11 13:06:01 PDT 1999
# Whom:			Michael Haro <mharo@area51.fremont.ca.us>
#
# $FreeBSD$
#

PORTNAME=	libmikmod
PORTVERSION=	3.1.11
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.raphnet.net/files/

MAINTAINER=	david@dyn-ns.net
COMMENT=	MikMod Sound Library

WANT_GNOME=	yes
USE_GNOME=	gnometarget lthack
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
MAKE_ENV=	SHELL=/bin/sh
INSTALLS_SHLIB=	yes

MAN1=		libmikmod-config.1
INFO=		mikmod

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-esd
PKGNAMESUFFIX=	-esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

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

.include <bsd.port.post.mk>
