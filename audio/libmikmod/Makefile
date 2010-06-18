# ports collection makefile for:	libmikmod
# Date created:		Sun Apr 11 13:06:01 PDT 1999
# Whom:			Michael Haro <mharo@area51.fremont.ca.us>
#
# $FreeBSD$
#

PORTNAME=	libmikmod
PORTVERSION=	3.1.11
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.raphnet.net/files/

PATCH_SITES=	http://mikmod.raphnet.net/files/
PATCHFILES=	libmikmod-3.1.11-a.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MikMod Sound Library

USE_AUTOTOOLS=	libtool:22
WANT_GNOME=	yes
USE_GNOME=	gnometarget lthack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
USE_LDCONFIG=	yes

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
