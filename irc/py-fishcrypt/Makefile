# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	py-fishcrypt
DISTVERSION=	4.21
CATEGORIES=	irc security
DIST_SUBDIR=	python

MAINTAINER=	koalative@gmail.com
COMMENT=	FiSH/Mircryption clone for XChat/HexChat

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto

USE_GITHUB=	yes
GH_ACCOUNT=	kwaaak
GH_TAGNAME=	c001c75

USES=		dos2unix python:run
NO_BUILD=	yes

SUB_FILES=	pkg-message

PORTDOCS=	README.md

PLIST_FILES=	%%DATADIR%%/fishcrypt.py

OPTIONS_DEFINE=	DOCS HEXCHAT XCHAT

HEXCHAT_DESC=		FiSH encryption for HexChat
XCHAT_DESC=		FiSH encryption for XChat

OPTIONS_SUB=	yes

HEXCHAT_RUN_DEPENDS=	hexchat:irc/hexchat
XCHAT_RUN_DEPENDS=	xchat:irc/xchat

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fishcrypt.py ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
