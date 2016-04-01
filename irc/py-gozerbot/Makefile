# Created by: Sten Spans <sten@blinkenlights.nl>
# $FreeBSD$

PORTNAME=	gozerbot
PORTVERSION=	0.8.1.1
PORTREVISION=	3
CATEGORIES=	irc python
MASTER_SITES=	http://gozerbot.org/media/tarball/ \
		GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	Gozerbot - A modular Python IRC and Jabber bot

USES=		python
USE_PYTHON=	distutils
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	XMPP MYSQL DOCS
XMPP_DESC=	Jabber functions
MYSQL_DESC=	Mysql functions

RUN_DEPENDS+=	${LOCALBASE}/bin/gpg:security/gnupg

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
	@${INSTALL_MAN} ${WRKSRC}/man/gozerbot.1.FreeBSD ${STAGEDIR}${MAN1PREFIX}/man/man1/gozerbot.1

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MXMPP}
RUN_DEPENDS+=${PYTHON_SITELIBDIR}/xmpp/__init__.py:net-im/py-xmpppy
.endif

.include <bsd.port.mk>
