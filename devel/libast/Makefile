# ports collection makefile for:	libast
# Date created:				7 September 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	libast
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.eterm.org/download/

MAINTAINER=	ishmael27x@yahoo.com

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS=	--enable-mmx
.endif

.include <bsd.port.post.mk>
