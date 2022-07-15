PORTNAME=	espeak
PORTVERSION=	4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	audio

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Espeak dialplan application for Asterisk

LICENSE=	GPLv2

LIB_DEPENDS=	libespeak-ng.so:audio/espeak-ng \
		libsamplerate.so:audio/libsamplerate

FLAVORS=	asterisk18 asterisk16
FLAVOR?=	${FLAVORS:[1]}

PKGNAMEPREFIX=		${FLAVOR}-
BUILD_DEPENDS=		asterisk:net/${FLAVOR}
RUN_DEPENDS=		asterisk:net/${FLAVOR}

USES=		compiler:c11 gmake localbase
INSTALL_TARGET=	install samples

CONFLICTS_INSTALL=	asterisk[0-9][0-9]-espeak # etc/asterisk/espeak.conf.sample

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
