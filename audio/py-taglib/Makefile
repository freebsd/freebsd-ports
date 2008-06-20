# New ports collection makefile for:	py-taglib
# Date created:		5 May 2006
# Whom:			Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	taglib
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://download.berlios.de/namingmuse/ \
		http://download2.berlios.de/namingmuse/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-taglib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the taglib audio file tagging library

BROKEN=		does not build with taglib 1.5

LIB_DEPENDS=	tag.6:${PORTSDIR}/audio/taglib

WRKSRC=		${WRKDIR}/python-taglib-${PORTVERSION}

USE_AUTOTOOLS=	libtool:15
USE_PYTHON=	-2.4
USE_PYTHON_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
