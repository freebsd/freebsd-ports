# New ports collection makefile for:	py-orbit
# Date created:		4 April 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	orbit
PORTVERSION=	0.2.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	orbit-python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	orbit-python-${PORTVERSION}

MAINTAINER=	johann@egenetics.com

LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit

USE_GMAKE=	yes
USE_GLIB=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
