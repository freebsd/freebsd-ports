# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fishcrypt
DISTVERSION=	5.31
PORTREVISION=	2
CATEGORIES=	irc security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FiSH/Mircryption-compatible encryption for HexChat

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	fladd
GH_PROJECT=	py-${PORTNAME}
GH_TAGNAME=	43554b1a

USES=		dos2unix python:3.6+,run shebangfix
USE_PYTHON=	flavors
SHEBANG_FILES=	fishcrypt.py
NO_BUILD=	yes

SUB_FILES=	pkg-message

PORTDOCS=	README.md

PLIST_FILES=	%%DATADIR%%/fishcrypt.py \
                %%DATADIR%%/pyBlowfish.py

OPTIONS_DEFINE=	DOCS HEXCHAT

HEXCHAT_DESC=		FiSH encryption for HexChat

OPTIONS_SUB=	yes

HEXCHAT_RUN_DEPENDS=	hexchat:irc/hexchat

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
