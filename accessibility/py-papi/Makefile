# New ports collection makefile for:	py-papi
# Date created:		2006-12-19
# Whom:			Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	papi
PORTVERSION=	0.0.2
CATEGORIES=	accessibility devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ocemp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	papi-${PORTVERSION}

MAINTAINER=	mva@sysfault.org
COMMENT=	ATK accessibility wrapper for python

USE_GNOME=	atk
USE_GCC=	3.4+
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -i "" -e 's|: docfiles|: []|g' ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
