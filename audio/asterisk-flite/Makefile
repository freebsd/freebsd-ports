PORTNAME=	flite
PORTVERSION=	3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flite dialplan application for Asterisk
WWW=		https://zaf.github.io/Asterisk-Flite/

LICENSE=	GPLv2

LIB_DEPENDS=	libflite.so:audio/flite

FLAVORS=			asterisk18
FLAVOR?=			${FLAVORS:[1]}

asterisk18_PKGNAMEPREFIX=       asterisk18-
asterisk18_BUILD_DEPENDS=       asterisk:net/asterisk18
asterisk18_RUN_DEPENDS=         asterisk:net/asterisk18

USES=		compiler:c11 gmake localbase
INSTALL_TARGET=	install samples

USE_GITHUB=	yes
GH_ACCOUNT=	zaf
GH_PROJECT=	Asterisk-Flite

CONFLICTS_INSTALL=	asterisk[0-9][0-9]-flite # etc/asterisk/flite.conf.sample

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-patch:
	@${REINPLACE_CMD} -e '/ASTERISK_REGISTER_FILE/d' \
		${WRKSRC}/app_flite.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/asterisk/modules/app_flite.so

.include <bsd.port.post.mk>
