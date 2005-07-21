# New ports collection makefile for:	Xfce Foundation Classes
# Date created:				1 Jun 2005
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfc
PORTVERSION=	4.3.1
CATEGORIES=	devel xfce
MASTER_SITES=	http://xfc.xfce.org/download/${PORTVERSION}/src/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The Xfce Foundation Classes

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GCC=	3.4+
USE_GNOME=	glib20 gtk20 atk pango pkgconfig libglade2 gnomehack
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

.include <bsd.port.post.mk>
