# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	mydumper
PORTVERSION=	0.10.5
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MySQL Data Dumper

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake:insource compiler:c11 gnome mysql pkgconfig ssl
USE_GNOME=	glib20

CMAKE_ARGS=	${CMAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
CMAKE_ARGS_gcc=	-DMYSQL_LIBRARIES_atomic:FILEPATH=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libatomic.so
CMAKE_OFF=	BUILD_DOCS WITH_BINLOG

PLIST_FILES=	sbin/mydumper sbin/myloader

GH_ACCOUNT=	maxbube
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/link_libraries(mydumper/ s|)$$| -lm)|; s|-Werror||' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mydumper ${WRKSRC}/myloader ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
