# New ports collection makefile for:   ecamegapedal
# Date created:                13 aug 2007
# Whom:                        lazyklimm <lazyklimm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ecamegapedal
PORTVERSION=	0.4.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/

MAINTAINER=	lazyklimm@gmail.com
COMMENT=	Realtime audio processor

BUILD_DEPENDS=	${LOCALBASE}/lib/libecasound.a:${PORTSDIR}/audio/ecasound

JACKDIR=	${LOCALBASE}/include/jack
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	${PTHREAD_CFLAGS:S/"//g}
LDFLAGS+=	${PTHREAD_LIBS:S/"//g}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		CXXFLAGS="-I${LOCALBASE}/include ${CXXFLAGS}"

MAN1=		ecamegapedal.1

.include <bsd.port.pre.mk>

.if defined(WITH_JACK)
CONFIGURE_ARGS+= --with-jack=${JACK_DIR}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+= --disable-jack
.endif

.include <bsd.port.post.mk>
