# New ports collection makefile for:	py-orbit
# Date created:		4 April 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	orbit
PORTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	# no longer available from original mastersite since December 2002
MASTER_SITE_SUBDIR=	orbit-python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	orbit-python-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org
COMMENT=	Python bindings for ORBit, a CORBA 2.2-compliant ORB

LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
