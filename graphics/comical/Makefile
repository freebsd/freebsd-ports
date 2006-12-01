# New ports collection makefile for:   comical
# Date created:        6 June 2005
# Whom:                John McAree <john@mcaree.org>
#
# $FreeBSD$
#

PORTNAME=	comical
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mcaree.org/Comical/ \
		http://www.sketchyorigins.com/Comical/

MAINTAINER=	john@mcaree.org
COMMENT=	A sequential image viewer

USE_GMAKE=	yes
USE_WX=		2.4
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"does not compile - not 64-bit clean"
.endif

.if ${OSVERSION} < 500000
BROKEN=		"does not compile with gcc-2.95"
.endif

.include <bsd.port.post.mk>
