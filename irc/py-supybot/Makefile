# New ports collection makefile for:	py-supybot
# Date created:		01 March 2004
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	supybot
PORTVERSION=	0.80.1
CATEGORIES=	irc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	supybot
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Supybot-${PORTVERSION}

MAINTAINER=	x@Vex.Net
COMMENT=	Supybot - A Superb Python IRC bot

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

DOCS=	ACKS BUGS ChangeLog DEVS INSTALL LICENSE README RELNOTES TODO

MANCOMPRESSED=	no
MAN1=	supybot.1 supybot-adduser.1 supybot-newplugin.1 supybot-wizard.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${MAN1}
	@${CP} ${WRKSRC}/docs/man/${f} ${PREFIX}/man/man1/
.endfor
.for f in ${DOCS}
	@${CP} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}/
.endif
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
