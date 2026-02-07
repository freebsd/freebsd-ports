PORTNAME=	liboil
PORTVERSION=	0.3.17
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of optimized inner loops
WWW=		https://liboil.freedesktop.org/wiki/

LICENSE=	BSD2CLAUSE BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=	configure
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--disable-glib
INSTALL_TARGET=	install-strip
CFLAGS:=	${CFLAGS:N-O*} -O2

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
USES+=		compiler:gcc-c++11-lib
.endif

.include <bsd.port.mk>
