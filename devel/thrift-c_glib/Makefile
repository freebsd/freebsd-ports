# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
DISTNAME=	thrift-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C glib interface to Thrift

BROKEN_powerpc64=	Does not build

PKGNAMESUFFIX=	-c_glib

BUILDIR=	${WRKDIR}/${DISTNAME}/lib/c_glib

LIB_DEPENDS=	libglib-2.0.so:devel/glib20

DISTINFO_FILE=	${.CURDIR}/../thrift/distinfo

USES=		autoreconf pkgconfig gmake libtool
GNU_CONFIGURE=	yes
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

post-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' ${WRKSRC}/lib/c_glib/Makefile.am

.include <bsd.port.mk>
