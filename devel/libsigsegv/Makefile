# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	libsigsegv
PORTVERSION=	2.12
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	Handling page faults in user mode

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	AWK="${AWK}" --enable-shared
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_FILES=	include/sigsegv.h \
		lib/libsigsegv.a \
		lib/libsigsegv.so \
		lib/libsigsegv.so.2 \
		lib/libsigsegv.so.2.0.5

.include <bsd.port.mk>
