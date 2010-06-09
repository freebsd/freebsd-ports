# New ports collection makefile for:	py-pg8000
# Date created:		2008-07-16
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pg8000
PORTVERSION=	1.08
CATEGORIES=	databases python
MASTER_SITES=	http://pybrary.net/pg8000/dist/:source1 \
		http://peak.telecommunity.com/dist/:source2
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:source1 \
		ez_setup.py:source2
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Pure-Python Interface to the PostgreSQL Database

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

post-extract:
	@${CP} ${DISTDIR}/ez_setup.py ${WRKSRC}/ez_setup.py

.include <bsd.port.mk>
