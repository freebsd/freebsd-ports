# Ports collection makefile for:	py-sgflib
# Date created:			January 16, 2004
# Whom:				Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	sgflib
PORTVERSION=	1.0
CATEGORIES=	games python
MASTER_SITES=	http://gotools.sourceforge.net/sgflib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	llwang@infor.org
COMMENT=	Smart Game Format Parser Library for Python

USE_PYTHON=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sgflib.py ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/typelib.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
