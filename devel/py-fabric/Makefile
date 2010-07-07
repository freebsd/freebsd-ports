# New ports collection makefile for:	py-fabric
# Date created:		2009-03-15
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fabric
PORTVERSION=	0.9.1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	http://code.fabfile.org/projects/fabric/files/ \
		http://distfiles.yzlin.org/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Fabric-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A simple pythonic remote deployment tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=1.9:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Fabric

PLIST_FILES=	bin/fab \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
