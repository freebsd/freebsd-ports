# New ports collection makefile for:	py-twisted
# Date created:		16 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twisted
PORTVERSION=	10.1.0
CATEGORIES=	devel net python
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	python@FreeBSD.org
COMMENT=	Metaport of Twisted, an event-driven networking engine

NO_BUILD=	yes
USE_PYTHON=	yes
PYDISTUTILS_NOEGGINFO=	yes

WRKSRC=		${WRKDIR}/Twisted-${PORTVERSION}

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore

OPTIONS=	CONCH	"SSH and SFTP protocol" on \
		LORE	"Documentation generator" on \
		MAIL	"SMTP, IMAP and POP protocol" on \
		NAMES	"DNS protocol" on \
		NEWS	"NNTP protocol" on \
		RUNNER	"Process management" on \
		WEB	"HTTP protocol" on \
		WORDS	"Chat and Instant Messaging" on

do-install:
	${DO_NADA}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CONCH)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/conch/__init__.py:${PORTSDIR}/security/py-twistedConch
.endif

.if !defined(WITHOUT_FLOW)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/flow/__init__.py:${PORTSDIR}/devel/py-twistedFlow
.endif

.if !defined(WITHOUT_MAIL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/mail/__init__.py:${PORTSDIR}/mail/py-twistedMail
.endif

.if !defined(WITHOUT_NAMES)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/names/__init__.py:${PORTSDIR}/dns/py-twistedNames
.endif

.if !defined(WITHOUT_NEWS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/news/__init__.py:${PORTSDIR}/news/py-twistedNews
.endif

.if !defined(WITHOUT_PAIR)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/pair/__init__.py:${PORTSDIR}/net/py-twistedPair
.endif

.if !defined(WITHOUT_RUNNER)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/runner/__init__.py:${PORTSDIR}/devel/py-twistedRunner
.endif

.if !defined(WITHOUT_LORE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/lore/__init__.py:${PORTSDIR}/textproc/py-twistedLore
.endif

.if !defined(WITHOUT_WEB)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb
.endif

.if !defined(WITHOUT_WEB2)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/web2/__init__.py:${PORTSDIR}/www/py-twistedWeb2
.endif

.if !defined(WITHOUT_WORDS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/words/__init__.py:${PORTSDIR}/net-im/py-twistedWords
.endif

.include <bsd.port.post.mk>
