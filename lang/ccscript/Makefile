# New ports collection makefile for:	ccscript
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccscript
PORTVERSION=	1.1.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME:S/$/3/}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	State-event driven class extendible C++ script interpreter

LIB_DEPENDS=	ccgnu2-1.6.0:${PORTSDIR}/devel/commoncpp

BROKEN=		Does not build with libtool 2.2.

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pkgconfig gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
