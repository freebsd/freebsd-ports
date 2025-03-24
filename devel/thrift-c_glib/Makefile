PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
DISTNAME=	thrift-${PORTVERSION}
PKGNAMESUFFIX=	-c_glib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C glib interface to Thrift
WWW=		https://thrift.apache.org/

BUILDIR=	${WRKDIR}/${DISTNAME}/lib/c_glib

DISTINFO_FILE=	${.CURDIR}/../thrift/distinfo

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		bison cmake compiler:c++11-lang cpe gnome pathfix \
		pkgconfig ssl
CPE_VENDOR=	apache
CMAKE_ON=	BUILD_C_GLIB
CMAKE_OFF=	BUILD_CPP BUILD_HASKELL BUILD_JAVA BUILD_JAVASCRIPT \
		BUILD_NODEJS BUILD_PYTHON
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include "../thrift/bsd.thrift.mk"

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} 's,-Werror,,' ${WRKSRC}/compiler/cpp/Makefile.am \
		${WRKSRC}/lib/rb/ext/extconf.rb

.include <bsd.port.mk>
