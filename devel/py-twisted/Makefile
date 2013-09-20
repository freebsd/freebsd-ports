# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twisted
PORTVERSION=	13.1.0
CATEGORIES=	devel net python
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# empty

MAINTAINER=	python@FreeBSD.org
COMMENT=	Metaport of Twisted, an event-driven networking engine

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedCore>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedCore

NO_BUILD=	yes
USE_PYTHON=	-2.7
PYDISTUTILS_NOEGGINFO=	yes

OPTIONS_DEFINE=	CONCH LORE MAIL NAMES NEWS PAIR RUNNER WEB WORDS
OPTIONS_DEFAULT=CONCH LORE MAIL NAMES NEWS PAIR RUNNER WEB WORDS
CONCH_DESC=	SSH and SFTP protocol
LORE_DESC=	Documentation generator
MAIL_DESC=	SMTP, IMAP and POP protocol
NAMES_DESC=	DNS protocol
NEWS_DESC=	NNTP protocol
PAIR_DESC=	Twisted Pair can do low level TCP work
RUNNER_DESC=	Process management
WEB_DESC=	HTTP protocol
WORDS_DESC=	Chat and Instant Messaging

# Bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
do-install:
	@${DO_NADA}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONCH}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedConch>=${PORTVERSION}:${PORTSDIR}/security/py-twistedConch
.endif

.if ${PORT_OPTIONS:MLORE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedLore>=${PORTVERSION}:${PORTSDIR}/textproc/py-twistedLore
.endif

.if ${PORT_OPTIONS:MMAIL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedMail>=${PORTVERSION}:${PORTSDIR}/mail/py-twistedMail
.endif

.if ${PORT_OPTIONS:MNAMES}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedNames>=${PORTVERSION}:${PORTSDIR}/dns/py-twistedNames
.endif

.if ${PORT_OPTIONS:MNEWS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedNews>=${PORTVERSION}:${PORTSDIR}/news/py-twistedNews
.endif

.if ${PORT_OPTIONS:MPAIR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedPair>=${PORTVERSION}:${PORTSDIR}/net/py-twistedPair
.endif

.if ${PORT_OPTIONS:MRUNNER}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedRunner>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedRunner
.endif

.if ${PORT_OPTIONS:MWEB}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedWeb>=${PORTVERSION}:${PORTSDIR}/www/py-twistedWeb
.endif

.if ${PORT_OPTIONS:MWORDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twistedWords>=${PORTVERSION}:${PORTSDIR}/net-im/py-twistedWords
.endif

.include <bsd.port.mk>
