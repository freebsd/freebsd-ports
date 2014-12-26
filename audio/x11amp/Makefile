# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x11amp
PORTVERSION=	0.9.b1.1
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	LOCAL/hrs
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/-beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11-based MP3 player with nice graphical interface

LICENSE=	GPLv2

BROKEN=		hangs at start with gtk and linker errors
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-01-26

USES=		libtool
USE_GNOME=	gtk12 esound
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

post-extract:
	@${CP} ${FILESDIR}/main.xpm ${WRKSRC}/x11amp/defskin

post-patch:
	@${REINPLACE_CMD} 's|-o root -g wheel||' ${WRKSRC}/libx11amp/Makefile.in

.include <bsd.port.mk>
