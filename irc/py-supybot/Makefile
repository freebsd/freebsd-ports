# Created by: Tim Middleton <x@vex.net>
# $FreeBSD$

PORTNAME=	supybot
PORTVERSION=	0.83.4.1
CATEGORIES=	irc python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Supybot-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Supybot-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supybot - A Superb Python IRC bot

USES=		python tar:bzip2
USE_PYTHON=	distutils
PYDISTUTILS_PKGVERSION=	0.83.1+darcs
PYDISTUTILS_EGGINFO=	supybot-${PORTVERSION}-py${PYTHON_VER}.egg-info

DOCS=	ACKS ChangeLog INSTALL LICENSE README RELNOTES

MAN1=	supybot.1 supybot-adduser.1 supybot-wizard.1 supybot-botchk.1 \
	supybot-plugin-create.1 supybot-plugin-doc.1

OPTIONS_DEFINE=	DOCS

post-install:
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/man/${f} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/GETTING_STARTED ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
