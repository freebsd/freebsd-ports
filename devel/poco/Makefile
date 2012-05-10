# ex:ts=8
# New ports collection makefile for:	poco
# Date created:			Nov 30, 2006
# Whom:				wes
#
# $FreeBSD$
#

PORTNAME=	poco
PORTVERSION=	1.4.3
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}p1

MAINTAINER=	wes@FreeBSD.org
COMMENT=	C++ Portable Components library

CONFLICTS=	poco-ssl-[0-9]*

OPTIONS=	TESTS   "Build testsuites" off \
		SAMPLES "Build sample programs" off

CONFIGURE_ARGS= --config=FreeBSD

.if !defined(WITH_TESTS)
CONFIGURE_ARGS+= --no-tests
.endif

.if !defined(WITH_SAMPLES)
CONFIGURE_ARGS+= --no-samples
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
