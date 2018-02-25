# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	quickfix
PORTVERSION=	1.14.3
CATEGORIES=	finance devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Free FIX Protocol Implementation

LICENSE=	GPLv3+

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake iconv libtool shebangfix ssl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
SHEBANG_FILES=	examples/tradeclientgui/banzai/build.sh
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=${CXX} CC=${CC} LIBS=-L${LOCALBASE}/lib/
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	MYSQL PGSQL PYTHON RUBY JAVA
OPTIONS_DEFAULT=	MYSQL
OPTIONS_SUB=	YES
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	postgresql
MYSQL_USES=	mysql
MYSQL_CONFIGURE_WITH=	mysql
PYTHON_USES=	python
PYTHON_CONFIGURE_WITH=	python
RUBY_USE=	ruby=yes
RUBY_CONFIGURE_WITH=	ruby
JAVA_USE=	java=yes
JAVA_CONFIGURE_WITH=	java

INSTALL_TARGET=install-strip

post-extract:
	@${REINPLACE_CMD} -e 's|^make|gmake|' \
		${WRKSRC}/src/ruby/make_ruby.sh
	@${REINPLACE_CMD} -e 's|CXX = g++|CXX = ${CXX}|' \
		${WRKSRC}/UnitTest++/Makefile
	@${REINPLACE_CMD} -e 's|pkgconfdir = .*|pkgconfdir=${LOCALBASE}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
post-configure:
	${GMAKE} -C ${WRKSRC}/UnitTest++ TestUnitTest++

post-install-RUBY-on:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITELIBDIR}/quickfix.so

.include <bsd.port.mk>
