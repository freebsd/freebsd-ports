# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	opencc
PORTVERSION=	0.4.3
CATEGORIES=	chinese converters
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	lichray@gmail.com
COMMENT=	Open Chinese Convert library and utilities

LICENSE=	APACHE20

USES=		cmake
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CMAKE_ON=	-DENABLE_GETTEXT=On

OPTIONS_SUB=	yes

BROKEN_powerpc=	Does not install on powerpc: signal 11

post-patch:
	@${REINPLACE_CMD} -e 's@/usr/local@${LOCALBASE}@g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
