# New ports collection makefile for:   soundtracker
# Date created:        28 November 1999
# Whom:                kzentner
#
# $FreeBSD$
#

PORTNAME=	soundtracker
PORTVERSION=	0.6.2
CATEGORIES=	audio gnome
MASTER_SITES=	ftp://ftp.soundtracker.org/pub/soundtracker/v0.6/

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME=	gnomelibs esound gnomeprefix gnomehack
CONFIGURE_ARGS+=--enable-gnome
PKGNAMESUFFIX=	-gnome
.else
CONFIGURE_ARGS+=--disable-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
