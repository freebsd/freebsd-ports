# New ports collection makefile for:   comical
# Date created:        6 June 2005
# Whom:                John McAree <john@mcaree.org>
#
# $FreeBSD$
#

PORTNAME=	comical
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	http://www.mcaree.org/Comical/ \
		http://www.sketchyorigins.com/Comical/

MAINTAINER=	john@mcaree.org
COMMENT=	A sequential image viewer

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--with-wx-config=${X11BASE}/bin/wxgtk2-2.4-config

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"does not compile - not 64-bit clean"
.endif

.if ${OSVERSION} < 500000
BROKEN=		"does not compile with gcc-2.95"
.endif

.include <bsd.port.post.mk>
