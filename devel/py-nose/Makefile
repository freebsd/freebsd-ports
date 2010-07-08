# New ports collection makefile for:	py-nose
# Date created:		14 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	nose
PORTVERSION=	0.11.3
CATEGORIES=	devel python
MASTER_SITES=	http://somethingaboutorange.com/mrl/projects/nose/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A discovery-based unittest extension

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
MAN1=		nosetests.1

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

post-install:
	${INSTALL_MAN} ${WRKSRC}/nosetests.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
