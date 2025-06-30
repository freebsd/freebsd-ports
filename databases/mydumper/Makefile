PORTNAME=	mydumper
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.4-2
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MySQL Data Dumper
WWW=		https://github.com/mydumper/mydumper

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake:insource compiler:c11 gnome mysql pkgconfig ssl
USE_GNOME=	glib20

CMAKE_ARGS=	${CMAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
CMAKE_ARGS_gcc=	-DMYSQL_LIBRARIES_atomic:FILEPATH=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libatomic.so
CMAKE_OFF=	BUILD_DOCS WITH_BINLOG
CMAKE_ON=	WITH_GLIB_uuid_string_random WITH_SSL

PLIST_FILES=	sbin/mydumper sbin/myloader

USE_GITHUB=	yes

PORTSCOUT=	ignore:1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mydumper ${WRKSRC}/myloader ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
