# New ports collection makefile for:	lwp
# Date created:				Tue Mar 21 17:51:25 EST 2000
# Whom:					jaharkes
#
# $FreeBSD$
#

PORTNAME=	lwp
PORTVERSION=	1.12
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/lwp/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A userspace thread library

USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		"Does not compile on !i386 and !alpha"
.endif

.include <bsd.port.post.mk>
