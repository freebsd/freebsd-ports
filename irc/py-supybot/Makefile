# New ports collection makefile for:	py-supybot
# Date created:		01 March 2004
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	supybot
PORTVERSION=	0.83.3
CATEGORIES=	irc python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Supybot-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Supybot - A Superb Python IRC bot

USE_BZIP2=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.83.1+darcs
PYDISTUTILS_EGGINFO=	supybot-${PORTVERSION}-py${PYTHON_VER}.egg-info

DOCS=	ACKS ChangeLog INSTALL LICENSE README RELNOTES

MANCOMPRESSED=	no
MAN1=	supybot.1 supybot-adduser.1 supybot-wizard.1 supybot-botchk.1 \
	supybot-plugin-create.1 supybot-plugin-doc.1

post-install:
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/man/${f} ${MAN1PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/GETTING_STARTED ${DOCSDIR}
.endif
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
