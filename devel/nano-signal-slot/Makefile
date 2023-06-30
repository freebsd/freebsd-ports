PORTNAME=	nano-signal-slot
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1-19
DISTVERSIONSUFFIX=	-g982b5ed
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pure C++17 signals and slots
WWW=		https://github.com/NoAvailableAlias/nano-signal-slot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	NoAvailableAlias

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/nano-signal-slot/nano_function.hpp \
		include/nano-signal-slot/nano_mutex.hpp \
		include/nano-signal-slot/nano_observer.hpp \
		include/nano-signal-slot/nano_signal_slot.hpp

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.hpp ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
