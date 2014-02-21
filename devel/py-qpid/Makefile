# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=		qpid
PORTVERSION=		0.26
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		${PORTNAME}-python-${PORTVERSION}

MAINTAINER=		zi@FreeBSD.org
COMMENT=		A Python library for qpid, a connection-oriented messaging API

LICENSE=		APACHE20

# Python3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME}_python
WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}/python

.include <bsd.port.mk>
