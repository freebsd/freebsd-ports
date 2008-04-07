# New ports collection makefile for:	libcheck
# Date created:		December 4, 2003
# Whom:			mikeh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libcheck
PORTVERSION=	0.9.5
CATEGORIES=	devel
MASTER_SITES=	SF/check

MAINTAINER=	mikeh@FreeBSD.org
COMMENT=	A unit test framework for C

GNU_CONFIGURE=	yes
PLIST_SUB=	CHECK_VERSION=${PORTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/check-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/check-${PORTVERSION}

INFO=		check

.include <bsd.port.mk>
