# New ports collection makefile for:	afternoonstalker
# Date created:			Feb 15, 2003
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	afternoonstalker
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www3.sympatico.ca/sarrazip/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the 1981 Night Stalker video game

LIB_DEPENDS=	gengameng.4:${PORTSDIR}/devel/gengameng

USE_SDL=	mixer sdl
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		afternoonstalker.6

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} "s@SDL/@SDL11/@g" ${WRKSRC}/configure \
		${WRKSRC}/src/SoundMixer.h
	${REINPLACE_CMD} "s@sounds/..PACKAGE.@afternoonstalker/sounds@g" \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
