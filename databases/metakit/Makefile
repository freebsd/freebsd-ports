# New ports collection makefile for:	metakit
# Date created:		25 December 1999
# Whom:			Russell L. Carter <rcarter@pinyon.org>
#
# $FreeBSD$
#

PORTNAME=	metakit
PORTVERSION=	2.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rcarter@pinyon.org

WRKSRC=		${WRKDIR}/${DISTNAME}/builds
USE_LIBTOOL=	yes
INSTALLS_SHLIBS=	yes
LIBTOOLFILES=	../unix/aclocal.m4
CONFIGURE_SCRIPT= ../unix/configure
MAKE_ARGS=	CXXFLAGS="-Dq4_STD ${CFLAGS}"

post-configure:
	@cd ${WRKSRC} ; \
	${PATCH} < ${FILESDIR}/patch.Makefile

.include <bsd.port.mk>
