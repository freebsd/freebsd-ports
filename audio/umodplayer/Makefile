# New ports collection makefile for:	umodplayer
# Date created:		14 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	umodplayer
PORTVERSION=	0.b4
DISTVERSION=	B4
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Console module player

LIB_DEPENDS=	modplug.0:${PORTSDIR}/audio/libmodplug \
		ao.3:${PORTSDIR}/audio/libao
BUILD_DEPENDS=	${LOCALBASE}/lib/libaiff.a:${PORTSDIR}/audio/libaiff

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's/CFLAGS =/CFLAGS +=/' ${WRKSRC}/${MAKEFILE}.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
