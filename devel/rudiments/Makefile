# New ports collection makefile for:	rudiments
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudiments
PORTVERSION=	0.28.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility C++ class library for daemons, clients, servers and more

USE_GNOME=		pkgconfig
USE_GMAKE=		yes
USE_OPENSSL=		yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=		--with-ssl-includes=-I${OPENSSLBASE}/include \
			--with-ssl-libs=-L${OPENSSLBASE}/lib --disable-pcre
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		PTHREADINCLUDES="${PTHREAD_CFLAGS}" \
			PTHREADLIB="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
