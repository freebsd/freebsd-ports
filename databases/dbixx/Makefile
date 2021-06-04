# Created by: Mohammad S. Babaei <info@babaei.net>

PORTNAME=	dbixx
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF/cppcms/${PORTNAME}/${PORTVERSION}

MAINTAINER=	info@babaei.net
COMMENT=	Tiny C++ wrapper around libdbi for database and SQL connectivity

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libdbi.so:databases/libdbi
BUILD_DEPENDS=	libdbi-drivers>=0:databases/libdbi-drivers

GNU_CONFIGURE=	yes
USES=		libtool localbase:ldflags pathfix
USE_LDCONFIG=	yes
USE_GCC=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/dbixx/dbixx.h \
		lib/libdbixx.a \
		lib/libdbixx.so \
		lib/libdbixx.so.2 \
		lib/libdbixx.so.2.0.0

.include <bsd.port.mk>
