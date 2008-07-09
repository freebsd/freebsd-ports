# New ports collection makefile for:	py-mpd
# Date created:		2008-04-05
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpd
PORTVERSION=	0.2.1
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python MPD client library

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_mpd

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/commands.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
