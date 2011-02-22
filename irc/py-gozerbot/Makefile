# New ports collection makefile for:	py-gozerbot
# Date created:		Wed Sep 19 00:04:39 CEST 2007
# Whom:			Sten Spans <sten@blinkenlights.nl>
#
# $FreeBSD$
#

PORTNAME=	gozerbot
PORTVERSION=	0.8.1.1
PORTREVISION=	1
CATEGORIES=	irc python
MASTER_SITES=	http://gozerbot.org/media/tarball/ \
		${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gozerbot-${PORTVERSION}

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	Gozerbot - A modular Python IRC and Jabber bot

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
SUB_FILES=		pkg-message

OPTIONS=	XMPP  "Jabber functions" off \
		MYSQL "Mysql functions" off
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

MAN1=		gozerbot.1

RUN_DEPENDS+=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg

post-install:
	@${CAT} ${PKGMESSAGE}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	${CP} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${INSTALL_MAN} ${WRKSRC}/man/gozerbot.1.FreeBSD ${PREFIX}/man/man1/gozerbot.1

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif

.if defined(WITH_XMPP)
RUN_DEPENDS+=${PYTHON_SITELIBDIR}/xmpp/__init__.py:${PORTSDIR}/net-im/py-xmpppy
.endif

.include <bsd.port.post.mk>
