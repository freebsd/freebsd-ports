# New ports collection makefile for:	py-hgsvn
# Date created:				2007-12-12
# Whom:					Xin LI <delphij@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hgsvn
PORTVERSION=	0.1.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	A set of scripts to work locally on Subversion checkouts using Mercurial

DIST_SUBDIR=	python
USE_PYTHON=	2.5+
USE_PYDISTUTILS=easy_install
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}
RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		hg:${PORTSDIR}/devel/mercurial

.include <bsd.port.mk>
