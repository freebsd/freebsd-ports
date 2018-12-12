# $FreeBSD$

PORTNAME=	espeak
PORTVERSION=	4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Espeak dialplan application for Asterisk

LICENSE=	GPLv2

LIB_DEPENDS=	libespeak.so:audio/espeak \
		libsamplerate.so:audio/libsamplerate

FLAVORS=			asterisk13 asterisk15 asterisk16
FLAVOR?=			${FLAVORS[1]}

asterisk13_PKGNAMEPREFIX=	asterisk13-
asterisk13_CONFLICTS_INSTALL=	asterisk15-espeak asterisk16-espeak
asterisk13_BUILD_DEPENDS=	asterisk:net/asterisk13
asterisk13_RUN_DEPENDS=		asterisk:net/asterisk13

asterisk15_PKGNAMEPREFIX=	asterisk15-
asterisk15_CONFLICTS_INSTALL=	asterisk13-espeak asterisk16-espeak
asterisk15_BUILD_DEPENDS=	asterisk:net/asterisk15
asterisk15_RUN_DEPENDS=		asterisk:net/asterisk15

asterisk16_PKGNAMEPREFIX=	asterisk16-
asterisk16_CONFLICTS_INSTALL=	asterisk13-espeak asterisk15-espeak
asterisk16_BUILD_DEPENDS=	asterisk:net/asterisk16
asterisk16_RUN_DEPENDS=		asterisk:net/asterisk16

USES=		compiler gmake localbase
INSTALL_TARGET=	install samples

USE_GITHUB=	yes
GH_ACCOUNT=	zaf
GH_PROJECT=	Asterisk-eSpeak

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-patch:
	@${REINPLACE_CMD} -e '/ASTERISK_REGISTER_FILE/d' \
		${WRKSRC}/app_espeak.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/asterisk/modules/app_espeak.so

.include <bsd.port.post.mk>
