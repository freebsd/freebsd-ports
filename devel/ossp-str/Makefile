# New ports collection makefile for:   OSSP str
# Date created:                22 February 2004
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	str
PORTVERSION=	0.9.8
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/${PORTNAME}/
PKGNAMEPREFIX=	ossp-

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	A generic string library written in ISO-C

USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

MAN1=		str-config.1
MAN3=		str.3

test:
	cd ${WRKSRC}; make check

.include <bsd.port.mk>
