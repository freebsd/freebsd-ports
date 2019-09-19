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

BUILDIR=	${WRKDIR}/${DISTNAME}/lib/c_glib

DISTINFO_FILE=	${.CURDIR}/../thrift/distinfo

USES=		autoreconf compiler:c++11-lang pathfix pkgconfig gmake libtool
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

post-patch:
	@${REINPLACE_CMD} 's,-Werror,,' ${WRKSRC}/compiler/cpp/Makefile.am \
		${WRKSRC}/lib/rb/ext/extconf.rb

.include <bsd.port.mk>
