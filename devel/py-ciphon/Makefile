# ex:ts=8
# Ports collection makefile for:	py-ciphon
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ciphon
PORTVERSION=	0.3.5
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pythonsiphon
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A module for python that adds cpan-like functionality

RUN_DEPENDS=	${PYEXPAT}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${MV} -f ${PREFIX}/bin/ciphon.py ${PREFIX}/bin/ciphon

.include <bsd.port.mk>
