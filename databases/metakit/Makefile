# New ports collection makefile for:	metakit
# Version required:	2.0
# Date created:		25 December 1999
# Whom:			Russell L. Carter <rcarter@pinyon.org>
#
# $FreeBSD$
#

DISTNAME=	metakit-2.0
CATEGORIES=	databases
MASTER_SITES=	http://download.sourceforge.net/metakit/

MAINTAINER=	rcarter@pinyon.org

WRKSRC=		${WRKDIR}/${DISTNAME}/builds
USE_LIBTOOL=	yes
LIBTOOLFILES=	../unix/aclocal.m4
CONFIGURE_SCRIPT= ../unix/configure
MAKE_ARGS=	CXXFLAGS="-Dq4_STD ${CFLAGS}"

post-configure:
	@cd ${WRKSRC} ; \
	${PATCH} < ${FILESDIR}/patch.Makefile

.include <bsd.port.mk>
