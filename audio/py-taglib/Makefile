# New ports collection makefile for:	py-taglib
# Date created:		5 May 2006
# Whom:			Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	taglib
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	BERLIOS
MASTER_SITE_SUBDIR=	namingmuse
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-taglib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the taglib audio file tagging library

DEPRECATED=	Only compatible with Python 2.4. Please use audio/py-tagpy instead
EXPIRATION_DATE=2011-12-04

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib

WRKSRC=		${WRKDIR}/python-taglib-${PORTVERSION}

USE_AUTOTOOLS=	libtool
USE_PYTHON=	-2.4
USE_PYTHON_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
