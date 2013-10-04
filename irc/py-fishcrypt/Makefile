# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	py-fishcrypt
DISTVERSION=	4.21
CATEGORIES=	irc security
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	FiSH/Mircryption clone for XChat/HexChat

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto

USE_GITHUB=	yes
GH_ACCOUNT=	kwaaak
GH_PROJECT=	py-fishcrypt
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT= 	c001c75

USE_PYTHON_RUN=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PORTDOCS=	README.md

PLIST_FILES=	%%DATADIR%%/fishcrypt.py
PLIST_DIRS=     %%DATADIR%%

OPTIONS_DEFINE=	DOCS XCHAT HEXCHAT

XCHAT_DESC=		FiSH encryption for XChat
HEXCHAT_DESC=		FiSH encryption for HexChat

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXCHAT}
RUN_DEPENDS+=	xchat:${PORTSDIR}/irc/xchat
.endif

.if ${PORT_OPTIONS:MHEXCHAT}
RUN_DEPENDS+=	hexchat:${PORTSDIR}/irc/hexchat
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fishcrypt.py ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
