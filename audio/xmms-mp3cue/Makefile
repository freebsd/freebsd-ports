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

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_SUB=	PORTDOCS=${DISTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/*.c

.include <bsd.port.post.mk>
