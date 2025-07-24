PORTNAME=	flite
DISTVERSION=	3.0.20230702
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flite dialplan application for Asterisk
WWW=		https://zaf.github.io/Asterisk-Flite/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libflite.so:audio/flite

FLAVORS=	asterisk18 asterisk20 asterisk22
FLAVOR?=	${FLAVORS:[3]}

${FLAVOR}_PKGNAMEPREFIX=	${FLAVOR}-
${FLAVOR}_BUILD_DEPENDS=	asterisk:net/${FLAVOR}
${FLAVOR}_RUN_DEPENDS=		asterisk:net/${FLAVOR}

USES=		compiler:c11 gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	zaf
GH_PROJECT=	Asterisk-Flite
GH_TAGNAME=	a3ed85151a1c875471568a959dce1bb35cca109b

INSTALL_TARGET=	install samples

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:C|(.+)|\1-${PORTNAME}|} # etc/asterisk/flite.conf.sample

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/asterisk/modules/app_flite.so

.include <bsd.port.post.mk>
