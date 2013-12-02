# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x11amp
PORTVERSION=	0.9.b1.1
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	hrs
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/-beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11-based MP3 player with nice graphical interface

LICENSE=	GPLv2

USE_GNOME=	gtk12 esound
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

post-extract:
	@${CP} ${FILESDIR}/main.xpm ${WRKSRC}/x11amp/defskin
	@${CHMOD} a+x ${WRKSRC}/ltconfig

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
