# ex:ts=8
# Ports collection makefile for:	libsigcx
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsigcx
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extension of libSigC++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

USE_GNOME=	gnomehack gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-static --enable-shared
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
