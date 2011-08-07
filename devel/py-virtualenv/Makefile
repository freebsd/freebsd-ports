# New ports collection makefile for:	py-virtualenv
# Date created:		2007-10-10
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtualenv
PORTVERSION=	1.6.4
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Virtual Python Environment builder

PLIST_SUB=	PYVER=${PYTHON_VER} PIPVER=${PIPVER} DISTRIBUTEVER=${DISTRIBUTEVER}

# Python3 ready
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

PIPVER=	1.0.2
DISTRIBUTEVER=	0.6.19

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} index.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
