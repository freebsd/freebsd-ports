# New ports collection makefile for:	py-supybot
# Date created:		01 March 2004
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	supybot
PORTVERSION=	0.77.2
CATEGORIES=	irc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	supybot
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Supybot-${PORTVERSION}

MAINTAINER=	x@Vex.Net
COMMENT=	Supybot - A Superb Python IRC bot

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

DOCS=	ACKS BUGS ChangeLog DEVS LICENSE README RELNOTES TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${CP} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}/
.endif
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
