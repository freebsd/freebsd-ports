# New ports collection makefile for:	libtap
# Date created:				21 December 2004
# Whom:					Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtap
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nik
DISTNAME=	tap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library implementing the Test Anything Protocol

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=		tap.3

post-build:
	@${CAT} ${PKGMESSAGE}

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
