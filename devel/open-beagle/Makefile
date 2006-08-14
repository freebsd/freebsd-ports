# ex:ts=8
# Ports collection makefile for:	beagle
# Date created:			Jun 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	open-beagle
PORTVERSION=	2.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	beagle
DISTNAME=	beagle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Evolutionary Computation Framework

CONFLICTS=	beagle-[0-9]*
USE_GCC=	3.3+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimization
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
