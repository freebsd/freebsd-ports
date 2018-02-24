# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
DISTNAME=	thrift-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C glib interface to Thrift

PKGNAMESUFFIX=	-c_glib

BROKEN_powerpc64=	fails to link: Internal error: Segmentation fault (program ld)

BUILDIR=	${WRKDIR}/${DISTNAME}/lib/c_glib

DISTINFO_FILE=	${.CURDIR}/../thrift/distinfo

USES=		autoreconf pathfix pkgconfig gmake libtool
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

.include "../thrift/bsd.thrift.mk"

CONFIGURE_ARGS+=        \
		--with-c_glib \
		--without-cpp \
		--without-qt4 \
		--without-csharp \
		--without-erlang \
		--without-haskell \
		--without-java \
		--without-perl \
		--without-php \
		--without-php_extension \
		--without-python \
		--without-ruby \
		--without-go

.include <bsd.port.mk>
