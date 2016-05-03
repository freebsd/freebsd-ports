# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	py-fishcrypt
DISTVERSION=	5.31
CATEGORIES=	irc security
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	FiSH/Mircryption-compatible encryption for XChat/HexChat

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks

USE_GITHUB=	yes
GH_ACCOUNT=	fladd
GH_TAGNAME=	43554b1a

USES=		dos2unix python:run
NO_BUILD=	yes

SUB_FILES=	pkg-message

PORTDOCS=	README.md

PLIST_FILES=	%%DATADIR%%/fishcrypt.py \
                %%DATADIR%%/pyBlowfish.py

OPTIONS_DEFINE=	DOCS HEXCHAT XCHAT

HEXCHAT_DESC=		FiSH encryption for HexChat
XCHAT_DESC=		FiSH encryption for XChat

OPTIONS_SUB=	yes

HEXCHAT_RUN_DEPENDS=	hexchat:irc/hexchat
XCHAT_RUN_DEPENDS=	xchat:irc/xchat

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
