# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION}	# get these from bsd.thrift.mk. any upgrade needs to check ALL dependencies
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	Framework for scalable cross-language services development

LICENSE=	APACHE20

USES=		bison cmake compiler:c++11-lang libtool pkgconfig
USE_LDCONFIG=	yes

# For C++ support, use devel/thrift-cpp
# For C glib support, use devel/thrift-c_glib.
# For Perl support, use devel/p5-Thrift.
# For Python support, use devel/py-thrift.
# For Ruby support, use devel/rubygem-thrift.
# For PHP support, use devel/php5-thrift.
# For nodejs support, use devel/node-thrift.
# Other languages are not yet supported, please feel free to contribute
# using one of the leaf ports as an example.
CMAKE_OFF=	BUILD_CPP BUILD_C_GLIB BUILD_JAVA BUILD_JAVASCRIPT BUILD_NODEJS BUILD_PYTHON BUILD_HASKELL

.include <bsd.port.pre.mk>
.include "bsd.thrift.mk"

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} 's,-Werror,,' ${WRKSRC}/compiler/cpp/Makefile.am \
		${WRKSRC}/lib/rb/ext/extconf.rb

pre-configure:
	@${REINPLACE_CMD} '/config.h/d' ${WRKSRC}/lib/cpp/Makefile.am

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "For use with C++, the same compiler as used to build this port must be used"
	@${ECHO_MSG} "to compile and link your generated IDL bindings."
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: The Thrift white paper may be downloaded from:"
	@${ECHO_MSG} "http://thrift.apache.org/static/thrift-20070401.pdf"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
