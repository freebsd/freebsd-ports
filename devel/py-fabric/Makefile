# New ports collection makefile for:	py-fabric
# Date created:		2009-03-15
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fabric
PORTVERSION=	0.9a2
CATEGORIES=	devel python
MASTER_SITES=	http://distfiles.yzlin.org/ \
		http://git.fabfile.org/cgit.cgi/fabric/snapshot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A simple pythonic remote deployment tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.7:${PORTSDIR}/security/py-paramiko

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Fabric

PLIST_FILES=	bin/fab \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
