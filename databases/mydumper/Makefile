# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	mydumper
PORTVERSION=	0.9.3
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MySQL Data Dumper

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:devel/pcre

CMAKE_ARGS=	-DBUILD_DOCS=OFF -DWITH_BINLOG=OFF
USE_GNOME=	glib20
USES=		cmake gnome mysql pkgconfig

PLIST_FILES=	sbin/mydumper sbin/myloader

GH_ACCOUNT=	maxbube
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/link_libraries(mydumper/ s|)$$| -lm)|; s|-Werror||' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mydumper ${WRKSRC}/myloader ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
