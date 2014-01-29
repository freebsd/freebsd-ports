# Created by: Sten Spans <sten@blinkenlights.nl>
# $FreeBSD$

PORTNAME=	gozerbot
PORTVERSION=	0.8.1.1
PORTREVISION=	2
CATEGORIES=	irc python
MASTER_SITES=	http://gozerbot.org/media/tarball/ \
		${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gozerbot-${PORTVERSION}

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	Gozerbot - A modular Python IRC and Jabber bot

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
SUB_FILES=		pkg-message

OPTIONS_DEFINE=	XMPP MYSQL DOCS
XMPP_DESC=	Jabber functions
MYSQL_DESC=	Mysql functions
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

MAN1=		gozerbot.1

RUN_DEPENDS+=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	${CP} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${INSTALL_MAN} ${WRKSRC}/man/gozerbot.1.FreeBSD ${PREFIX}/man/man1/gozerbot.1

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MXMPP}
RUN_DEPENDS+=${PYTHON_SITELIBDIR}/xmpp/__init__.py:${PORTSDIR}/net-im/py-xmpppy
.endif

.include <bsd.port.mk>
