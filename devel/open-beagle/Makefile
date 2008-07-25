# ex:ts=8
# Ports collection makefile for:	beagle
# Date created:			Jun 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	open-beagle
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	beagle
DISTNAME=	beagle-${PORTVERSION}

MAINTAINER=	sf@slappy.org
COMMENT=	An Evolutionary Computation Framework

CONFLICTS=	beagle-[0-9]*
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimization
USE_LDCONFIG=	yes
USE_GMAKE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
