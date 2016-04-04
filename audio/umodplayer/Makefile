# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	umodplayer
PORTVERSION=	0.${DISTVERSION:tl}
DISTVERSION=	B5.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/UModPlayer%20B5
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console module player

LIB_DEPENDS=	libmodplug.so:audio/libmodplug \
		libao.so:audio/libao
BUILD_DEPENDS=	${LOCALBASE}/lib/libaiff.a:audio/libaiff

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/CFLAGS/s| =| +=| ; \
		 /CFLAGS/s| -O2| $$(CPPFLAGS)|g ; \
		 /^@/d' ${WRKSRC}/${MAKEFILE}.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
