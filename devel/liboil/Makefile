# Created by: ijliao
# $FreeBSD$
#    $MCom: ports/devel/liboil/Makefile,v 1.7 2008/03/23 06:57:57 marcus Exp $

PORTNAME=	liboil
PORTVERSION=	0.3.17
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of optimized inner loops

LICENSE=	BSD2CLAUSE BSD3CLAUSE MIT
LICENSE_COMB=	multi

BROKEN_powerpc64=	fails to compile vec_memcpy.S

USES=		libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=	configure
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--disable-glib
INSTALL_TARGET=	install-strip
CFLAGS:=	${CFLAGS:N-O*} -O2

.include <bsd.port.mk>
