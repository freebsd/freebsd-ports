# New ports collection makefile for:	XMMS-mp3cue
# Date created:			12 February 2004
# Whom:				Vaidas Zlotkus <r2@music.lt>
#
# $FreeBSD$
#

PORTNAME=	xmms-mp3cue
PORTVERSION=	0.94
CATEGORIES=	audio
MASTER_SITES=	http://brianvictor.tripod.com/
DISTNAME=	XMMS-mp3cue-${PORTVERSION}

MAINTAINER=	r2@music.lt
COMMENT=	XMMS mp3cue adds cue file support to XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

PLIST_SUB=	PORTDOCS=${DISTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fPIC"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/*.c

.include <bsd.port.post.mk>
