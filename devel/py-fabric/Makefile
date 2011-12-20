# New ports collection makefile for:	py-fabric
# Date created:		2009-03-15
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fabric
PORTVERSION=	1.3.3
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Fabric-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A simple pythonic remote deployment tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ssh>=1.7.8:${PORTSDIR}/security/py-ssh

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Fabric

.include <bsd.port.mk>
