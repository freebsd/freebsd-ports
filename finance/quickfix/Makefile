PORTNAME=	quickfix
PORTVERSION=	1.15.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	finance devel

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Free FIX Protocol Implementation

LICENSE=	GPLv3+

BROKEN_i386=	fails to build

BUILD_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake gnome iconv libtool shebangfix ssl

USE_GITHUB=	yes

USE_GNOME=	libxml2
USE_LDCONFIG=	yes
SHEBANG_FILES=	examples/tradeclientgui/banzai/build.sh
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=${CXX} CC=${CC} LIBS=-L${LOCALBASE}/lib/
CONFIGURE_ARGS+=	--without-python2

OPTIONS_DEFINE=	MYSQL PGSQL PYTHON RUBY JAVA
OPTIONS_DEFAULT=	MYSQL
OPTIONS_SUB=	YES
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	postgresql
MYSQL_USES=	mysql
MYSQL_CONFIGURE_WITH=	mysql
PYTHON_USES=	python:3.7
PYTHON_CONFIGURE_WITH=	python3
RUBY_USE=	ruby=yes
RUBY_CONFIGURE_WITH=	ruby
RUBY_LIB_DEPENDS+=libunwind.so:devel/libunwind
JAVA_USE=	java=yes
JAVA_CONFIGURE_WITH=	java

INSTALL_TARGET=install-strip

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CXXFLAGS+=	-DENABLE_BOOST_ATOMIC_COUNT
LIB_DEPENDS+=	libboost_system.so:devel/boost-libs
USES+=		compiler:c++11-lang localbase
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|^make|gmake|' \
		${WRKSRC}/src/ruby/make_ruby.sh
	@${REINPLACE_CMD} -e 's|CXX = g++|CXX = ${CXX}|' \
		${WRKSRC}/UnitTest++/Makefile
pre-configure:
	cd ${WRKSRC} && ${sh} ${WRKSRC}/bootstrap
	@${REINPLACE_CMD} -e 's|pkgconfdir = .*|pkgconfdir=${LOCALBASE}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
pre-build:
	${GMAKE} -C ${WRKSRC}/UnitTest++ TestUnitTest++

post-install-RUBY-on:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/quickfix.so

.include <bsd.port.mk>
