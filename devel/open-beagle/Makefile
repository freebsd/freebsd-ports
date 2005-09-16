# ex:ts=8
# Ports collection makefile for:	beagle
# Date created:			Jun 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	beagle
PORTVERSION=	2.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Evolutionary Computation Framework

USE_GCC=	3.3+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimization
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
