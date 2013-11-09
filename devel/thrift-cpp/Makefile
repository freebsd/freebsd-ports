# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	komarov@valerka.net
COMMENT=	C++ interface to Thrift

PKGNAMESUFFIX=	-cpp

MASTER_SITES=		APACHE
MASTER_SITE_SUBDIR=	thrift/${PORTVERSION}
DISTNAME=		thrift-${PORTVERSION}
DISTINFO_FILE=		${.CURDIR}/../thrift/distinfo

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libevent-1.4.so:${PORTSDIR}/devel/libevent

BUILDIR=		${WRKDIR}/${DISTNAME}/lib/cpp

USE_AUTOTOOLS=	autoconf autoheader:env aclocal automake libtool
ACLOCAL_ARGS=	-I${WRKSRC}/aclocal
AUTOMAKE_ARGS=	--foreign --add-missing --copy

USES=			pkgconfig gmake compiler
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB=		PORTVERSION="${THRIFT_PORTVERSION}"

OPTIONS_DEFINE=		QT4
QT4_CONFIGURE_WITH=	qt4

OPTIONS_SUB=		yes

CONFIGURE_ARGS+=        \
		--without-c_glib \
		--with-cpp \
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

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
USE_CXXSTD=	c++11
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=		network moc_build qmake_build rcc_build uic_build
.endif

post-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' ${WRKSRC}/lib/cpp/Makefile.am

post-install:
	@${LN} -sf ${PREFIX}/lib/libthrift-${PORTVERSION}.so ${PREFIX}/lib/libthrift.so.0
	@${LN} -sf ${PREFIX}/lib/libthriftnb-${PORTVERSION}.so ${PREFIX}/lib/libthriftnb.so.0
	@${LN} -sf ${PREFIX}/lib/libthriftz-${PORTVERSION}.so ${PREFIX}/lib/libthriftz.so.0
.if ${PORT_OPTIONS:MQT4}
	@${LN} -sf ${PREFIX}/lib/libthriftqt-${PORTVERSION}.so ${PREFIX}/lib/libthriftqt.so.0
.endif

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
