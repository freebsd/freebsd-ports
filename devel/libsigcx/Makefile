# ex:ts=8
# Ports collection makefile for:	libsigcx
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsigcx
PORTVERSION=	0.6.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extension of libSigC++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

USE_GNOME=	gnomehack gnometarget gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}" \
		ac_cv_path_DOXYGEN=""
USE_LDCONFIG=	yes

.include <bsd.port.mk>
