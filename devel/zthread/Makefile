# New ports collection makefile for:	ZThread
# Date created:				23 May 2001
# Whom:					pvh@egenetics.com
#
# $FreeBSD$
#

PORTNAME=	zthread
PORTVERSION=	1.4.4
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.buffalo.edu/%7Ecrahen/projects/zthread/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ZThread-${PORTVERSION}

MAINTAINER=	pvh@egenetics.com

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

HAS_CONFIGURE=	yes

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
