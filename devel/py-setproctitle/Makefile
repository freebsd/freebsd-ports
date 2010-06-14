# New ports collection makefile for:	py-setproctitle
# Date created:		2010-03-12
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	setproctitle
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Allow customization of the process title

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}.so

PORTDOCS=	COPYRIGHT HISTORY README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
