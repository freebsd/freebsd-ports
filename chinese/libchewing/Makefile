PORTNAME=	libchewing
PORTVERSION=	0.12.0
CATEGORIES=	chinese textproc
MASTER_SITES=	https://github.com/chewing/libchewing/releases/download/v${PORTVERSION}/
DISTFILES=	libchewing-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chewing intelligent phonetic input method library
WWW=		https://chewing.im/ \
		https://codeberg.org/chewing/libchewing

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	corrosion>=0:devel/corrosion

USES=		cargo cmake:testing localbase:ldflags pkgconfig sqlite tar:zst

CARGO_BUILD=	no
CARGO_INSTALL=	no
CMAKE_OFF=	BUILD_INFO \
		BUILD_TESTING \
		ENABLE_GCOV \
		USE_SYSTEM_CHEWING_CLI \
		USE_VALGRIND
CMAKE_ON=	BUILD_DATA \
		BUILD_SHARED_LIBS \
		COMPRESS_MANS \
		NO_UNDEFINED \
		WITH_SQLITE3
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_CMAKE_BOOL=	BUILD_DOC

.include <bsd.port.mk>
