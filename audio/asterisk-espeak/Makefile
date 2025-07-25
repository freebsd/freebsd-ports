PORTNAME=	espeak
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Espeak dialplan application for Asterisk
WWW=		https://zaf.github.io/Asterisk-eSpeak/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libespeak-ng.so:audio/espeak-ng \
		libsamplerate.so:audio/libsamplerate

FLAVORS=	asterisk18 asterisk20 asterisk22
FLAVOR?=	${FLAVORS:[3]}

${FLAVOR}_PKGNAMEPREFIX=	${FLAVOR}-
${FLAVOR}_BUILD_DEPENDS=	asterisk:net/${FLAVOR}
${FLAVOR}_RUN_DEPENDS=		asterisk:net/${FLAVOR}

USES=		compiler:c11 gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	zaf
GH_PROJECT=	Asterisk-eSpeak

INSTALL_TARGET=	install samples

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:C|(.+)|\1-${PORTNAME}|} # etc/asterisk/espeak.conf.sample

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/asterisk/modules/app_espeak.so

.include <bsd.port.post.mk>
