# New ports collection makefile for:	py-nose
# Date created:		14 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	nose
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	http://somethingaboutorange.com/mrl/projects/nose/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A discovery-based unittest extension

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		nosetests.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/nosetests.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
