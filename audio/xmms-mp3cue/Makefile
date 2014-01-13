# Created by: Vaidas Zlotkus <r2@music.lt>
# $FreeBSD$

PORTNAME=	xmms-mp3cue
PORTVERSION=	0.94
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://brianvictor.tripod.com/
DISTNAME=	XMMS-mp3cue-${PORTVERSION}

MAINTAINER=	r2@music.lt
COMMENT=	XMMS mp3cue adds cue file support to XMMS

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_SUB=	PORTDOCS=${DISTNAME}

CFLAGS_amd64=	-fPIC
CFLAGS_ia64=	-fPIC
MAKE_ARGS+=	CC="${CXX}"

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/*.c

.include <bsd.port.mk>
