# Ports collection Makefile for:	py-sendfile
# Date created:				02/01/2004
# Whom:					ports@tautology.org
#
# $FreeBSD$
#

PORTNAME=	sendfile
PORTVERSION=	1.2.2
CATEGORIES=	devel python
MASTER_SITES=	http://tautology.org/software/python-modules/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-sendfile-${PORTVERSION}

MAINTAINER=	ports@tautology.org
COMMENT=	Python interface to the sendfile(2) system call

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/sendfile.so

.include <bsd.port.mk>
