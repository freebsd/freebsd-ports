# New ports collection makefile for:	py-orbit
# Date created:		4 April 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	orbit
PORTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	http://orbit-python.sault.org/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	orbit-python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	orbit-python-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
