PORTNAME=	libsigsegv
DISTVERSION=	2.15
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	Handling page faults in user mode
WWW=		https://www.gnu.org/software/libsigsegv/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	AWK="${AWK}" --enable-shared
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_FILES=	include/sigsegv.h \
		lib/libsigsegv.a \
		lib/libsigsegv.so \
		lib/libsigsegv.so.2 \
		lib/libsigsegv.so.2.0.8

.include <bsd.port.mk>
