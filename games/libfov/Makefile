# New ports collection makefile for:    libfov
# Date created:         12 Jan 2006
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libfov
PORTVERSION=	0.1.2
CATEGORIES=	games devel
MASTER_SITES=	http://members.optushome.com.au/puyo/dev/libfov/

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	This C library implements a course-grained lighting algorithm

WRKSRC=		${WRKDIR}/${DISTNAME}/src
INSTALLS_SHLIB=	yes

post-extract:
	@${CP} ${PATCHDIR}/Makefile.bsd ${WRKSRC}/Makefile

.include <bsd.port.mk>
