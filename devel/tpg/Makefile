# Ports collection makefile for:	tpg
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tpg
PORTVERSION=	3.1.1
CATEGORIES=	devel python
MASTER_SITES=	http://christophe.delord.free.fr/soft/tpg/
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parser generator in Python

USE_PYTHON=		2.2+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TPG

NO_BUILD=	yes

DOCS=		ChangeLog README THANKS doc/tpg.pdf
EXAMPLES=	examples/*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
