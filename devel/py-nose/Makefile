# New ports collection makefile for:	py-nose
# Date created:		14 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	nose
PORTVERSION=	0.9.2
CATEGORIES=	devel python
MASTER_SITES=	http://somethingaboutorange.com/mrl/projects/nose/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A discovery-based unittest extension

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
MAN1=		nosetests.1
NOSEVER?=	${PORTVERSION}
PYTHONVER?=	${_PYTHON_VERSION}
PLIST_SUB=	NOSEVER=${NOSEVER} \
		PYTHONVER=${PYTHONVER}

post-install:
	${INSTALL_MAN} ${WRKSRC}/nosetests.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
