# New ports collection makefile for:	kimagemapeditor
# Date created:				19 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	kimagemapeditor
PORTVERSION=	1.0
CATEGORIES=	graphics kde
MASTER_SITES=	http://savannah.nongnu.org/download/kimagemap/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	KDE-based editor for HTML image maps

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
