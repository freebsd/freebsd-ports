# New ports collection makefile for:   OSSP xds
# Date created:                22 February 2004
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	xds
PORTVERSION=	0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A generic and extensible framework for serialization

USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

MAN1=		xds-config.1
MAN3=		xds.3

test:
	cd ${WRKSRC}; make check

.include <bsd.port.mk>
