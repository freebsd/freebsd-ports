# ports collection makefile for:	gigabase
# Date created:			15 August 2000
# Whom:				Sergey A. Osokin <osa@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	gigabase
PORTVERSION=	3.45
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.garret.ru/~knizhnik/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Object-Relational Database Management System

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS?=--prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

post-install:
	@${INSTALL_DATA} ${WRKSRC}/rtree.h ${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
