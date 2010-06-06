# New ports collection makefile for:	umodplayer
# Date created:		14 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	umodplayer
PORTVERSION=	0.${DISTVERSION:L}
DISTVERSION=	B5.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/UModPlayer%20B5
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console module player

LIB_DEPENDS=	modplug.1:${PORTSDIR}/audio/libmodplug \
		ao.4:${PORTSDIR}/audio/libao
BUILD_DEPENDS=	${LOCALBASE}/lib/libaiff.a:${PORTSDIR}/audio/libaiff

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/CFLAGS/s| =| +=| ; \
		 /CFLAGS/s| -O2| $$(CPPFLAGS)|g ; \
		 /^@/d' ${WRKSRC}/${MAKEFILE}.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
