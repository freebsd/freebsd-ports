# New ports collection makefile for:	libtap
# Date created:				21 December 2004
# Whom:					Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtap
PORTVERSION=	1.01
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nik
DISTNAME=	tap-${PORTVERSION}

MAINTAINER=	nik@FreeBSD.org
COMMENT=	Library implementing the Test Anything Protocol

GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

MAN3=		tap.3

post-build:
	${CAT} pkg-message

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
