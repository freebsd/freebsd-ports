# New ports collection makefile for:	py-supybot
# Date created:		01 March 2004
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	supybot
PORTVERSION=	0.77.0
CATEGORIES=	irc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	supybot
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Supybot-${PORTVERSION}

MAINTAINER=	x@Vex.Net
COMMENT=	Supybot - A Superb Python IRC bot

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/supybot

DOCS=		CAPABILITIES FAQ OVERVIEW CONFIGURATION \
			GETTING_STARTED RELEASE-CHECKLIST EXAMPLE \
			INTERFACES STYLE \
			../ACKS ../BUGS ../ChangeLog ../DEVS ../LICENSE \
			../README ../RELNOTES ../TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
