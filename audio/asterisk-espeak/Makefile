# $FreeBSD$

PORTNAME=	asterisk-espeak
PORTVERSION=	4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Espeak dialplan application for Asterisk

LICENSE=	GPLv2

LIB_DEPENDS=	libespeak.so:audio/espeak \
		libsamplerate.so:audio/libsamplerate
BUILD_DEPENDS=	asterisk:net/asterisk13
RUN_DEPENDS=	asterisk:net/asterisk13

USES=		compiler gmake localbase
INSTALL_TARGET=	install samples

USE_GITHUB=	yes
GH_ACCOUNT=	zaf
GH_PROJECT=	Asterisk-eSpeak

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/asterisk/modules/app_espeak.so

.include <bsd.port.post.mk>
