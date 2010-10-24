# New ports collection makefile for:	libobjc2
# Date created:		7 October 2010
# Whom:			Pete French <pete@twisted.org.uk>
#
# $FreeBSD$
#

PORTNAME=	libobjc2
PORTVERSION=	1.0
CATEGORIES=	lang devel gnustep
MASTER_SITES=	http://download.gna.org/gnustep/

MAINTAINER=	pete@twisted.org.uk
COMMENT=	Replacement Objective-C runtime supporting Obj-C 2 features

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_LDCONFIG=	yes

OPTIONS=	LIBDISPATCH "Build with libdispatch from ports" Off

.include <bsd.port.options.mk>

.if defined(WITH_LIBDISPATCH)
LIB_DEPENDS+=	dispatch.0:${PORTSDIR}/devel/libdispatch
MAKE_ARGS+=	-DWITHOUT_TOYDISPATCH
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.if (${ARCH} == i386) || (${ARCH} == i486)
CFLAGS+=	-march=i586
.endif

.include <bsd.port.post.mk>
