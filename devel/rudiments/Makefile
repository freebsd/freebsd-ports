# New ports collection makefile for:	rudiments
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudiments
PORTVERSION=	0.31
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility C++ class library for daemons, clients, servers and more

USE_GNOME=	gnometarget pkgconfig
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	PTHREADINCLUDES="${PTHREAD_CFLAGS}" \
		PTHREADLIB="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-ssl-includes=-I${OPENSSLINC} \
		--with-ssl-libs=-L${OPENSSLLIB} \
		--disable-pcre
USE_LDCONFIG=	yes

.include <bsd.port.mk>
