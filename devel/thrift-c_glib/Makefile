# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	komarov@valerka.net
COMMENT=	C glib interface to Thrift

PKGNAMESUFFIX=	-c_glib

MASTER_SITES=		APACHE
MASTER_SITE_SUBDIR=	/thrift/${PORTVERSION
DISTINFO_FILE=		${.CURDIR}/../thrift/distinfo
DISTNAME=		thrift-${PORTVERSION}

BUILDIR=	${WRKDIR}/${DISTNAME}/lib/c_glib

LIB_DEPENDS=	libglib-2.0.so:${PORTSDIR}/devel/glib20

USE_AUTOTOOLS=	autoconf autoheader:env aclocal automake libtool
ACLOCAL_ARGS=	-I${WRKSRC}/aclocal
AUTOMAKE_ARGS=	--foreign --add-missing --copy

USES=		pkgconfig gmake
GNU_CONFIGURE=  yes
USE_LDCONFIG=   yes
MAKE_JOBS_UNSAFE= yes

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
		--without-ruby

NO_STAGE=	yes

post-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' ${WRKSRC}/lib/c_glib/Makefile.am

.include <bsd.port.mk>
