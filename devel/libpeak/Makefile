# ex:ts=8
# Ports collection makefile for:	libpeak
# Date created:			Mar 18, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libpeak
PORTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	peak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel Events and Asynchronous tasKing Library

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	CFLAGS="${CFLAGS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
