# New ports collection makefile for:	py-pybugz
# Date created:				2012-03-18
# Whom:					Chris Rees <crees@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pybugz
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Command line tools for interacting with Bugzilla

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes

PLIST_FILES=	bin/bugz
DATADIR=	${PYTHONPREFIX_SITELIBDIR}/bugz
PORTDATA=	*

.include <bsd.port.mk>
