# ports collection makefile for:	gigabase
# Date created:			15 August 2000
# Whom:				Sergey Osokin aka oZZ <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gigabase
PORTVERSION=	2.77
CATEGORIES=	databases
MASTER_SITES=	http://www.garret.ru/~knizhnik/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
