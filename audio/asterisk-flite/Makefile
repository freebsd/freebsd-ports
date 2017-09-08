# $FreeBSD$

PORTNAME=	asterisk-flite
PORTVERSION=	3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Flite dialplan application for Asterisk

LICENSE=	GPLv2

LIB_DEPENDS=	libflite.so:audio/flite

USES=		compiler gmake localbase
INSTALL_TARGET=	install samples

USE_GITHUB=	yes
GH_ACCOUNT=	zaf
GH_PROJECT=	Asterisk-Flite

OPTIONS_SINGLE=	ASTVER
OPTIONS_SINGLE_ASTVER=	ASTERISK11 ASTERISK13

OPTIONS_DEFAULT=	ASTERISK13

ASTERISK11_DESC=	Depend on Asterisk 11
ASTERISK13_DESC=	Depend on Asterisk 13

ASTERISK11_BUILD_DEPENDS=	asterisk:net/asterisk11
ASTERISK11_RUN_DEPENDS=	asterisk:net/asterisk11
ASTERISK13_BUILD_DEPENDS=	asterisk:net/asterisk13
ASTERISK13_RUN_DEPENDS=	asterisk:net/asterisk13

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/asterisk/modules/app_flite.so

.include <bsd.port.post.mk>
