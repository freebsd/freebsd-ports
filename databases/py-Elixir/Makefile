# New ports collection makefile for:	py-Elixir
# Date created:		2007-02-13
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Elixir
PORTVERSION=	0.6.1
#PORTREVISION=	0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Declarative Mapper for SQLAlchemy

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.4.0:${PORTSDIR}/databases/py-sqlalchemy

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.if !defined(NOPORTEXAMPLES)
EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
