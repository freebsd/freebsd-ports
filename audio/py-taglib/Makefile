# New ports collection makefile for:	py-taglib
# Date created:		5 May 2006
# Whom:			Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	taglib
PORTVERSION=	1.3.3
CATEGORIES=	audio python
MASTER_SITES=	http://download.berlios.de/namingmuse/ \
		http://download2.berlios.de/namingmuse/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-taglib-${PORTVERSION}

MAINTAINER=	kbyanc@FreeBSD.org
COMMENT=	Python bindings for the taglib audio file tagging library

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib

WRKSRC=		${WRKDIR}/python-taglib-${PORTVERSION}

USE_PYTHON=	yes
USE_PYTHON_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
