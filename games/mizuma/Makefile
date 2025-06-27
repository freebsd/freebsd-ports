PORTNAME=	mizuma
DISTVERSION=	2025.06
CATEGORIES=	games emulators
MASTER_SITES=	https://codeberg.org/Alexander88207/Mizutamari/archive/${PORTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	User-friendly Wine front-end
WWW=		https://codeberg.org/Alexander88207/Mizutamari

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Wine only runs on x86 architecture

RUN_DEPENDS=	7zz:archivers/7-zip \
		bash:shells/bash \
		wine:emulators/wine \
		wine-mono>0:emulators/wine-mono \
		winetricks:emulators/winetricks \
		xdg-open:devel/xdg-utils \
		yad:x11/yad

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/mizutamari

PLIST_FILES=	bin/Mizuma \
		share/Mizutamari/Tools/Framework

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Mizutamari/Tools
	${INSTALL_SCRIPT} ${WRKSRC}/Mizuma ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Tools/Framework ${STAGEDIR}${PREFIX}/share/Mizutamari/Tools

.include <bsd.port.mk>
