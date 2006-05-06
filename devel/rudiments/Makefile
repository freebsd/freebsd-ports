# New ports collection makefile for:	rudiments
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudiments
PORTVERSION=	0.29
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	A utility C++ class library for daemons, clients, servers and more

USE_GNOME=	pkgconfig
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl-includes=-I${OPENSSLBASE}/include \
		--with-ssl-libs=-L${OPENSSLBASE}/lib --disable-pcre
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	PTHREADINCLUDES="${PTHREAD_CFLAGS}" \
		PTHREADLIB="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
PLIST_SUB+=	NOT4X="@comment "
.else
PLIST_SUB+=	NOT4X=""
.endif

.include <bsd.port.post.mk>
