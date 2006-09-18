# New ports collection makefile for:	umodplayer
# Date created:		14 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	umodplayer
PORTVERSION=	0.b5.1
DISTVERSION=	B5.1
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
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's/CFLAGS =/CFLAGS +=/' ${WRKSRC}/${MAKEFILE}.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
