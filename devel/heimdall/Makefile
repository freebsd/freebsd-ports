PORTNAME=	heimdall
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.2
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~grimler/Heimdall/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~grimler/Heimdall/commit/
PATCHFILES+=	72fe7627eb02.patch:-p1 # snprintf bugfix

MAINTAINER=	kenrap@FreeBSD.org
COMMENT=	Tool suite used to flash firmware onto Samsung mobile devices
WWW=		https://glassechidna.com.au/heimdall/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang pkgconfig

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17

WRKSRC=		${WRKDIR}/Heimdall-${DISTVERSIONFULL}

PLIST_FILES=	%%GUI%%bin/heimdall-frontend \
		bin/heimdall

PORTDOCS=	Heimdall-Firmware-Packages.md \
		Heimdall-Frontend-flash-instructions.md \
		Heimdall-flash-instructions.md

OPTIONS_DEFINE=		DOCS GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_USES=	qt:6
GUI_USE=	QT=base
GUI_CMAKE_OFF=	-DDISABLE_FRONTEND=YES

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/heimdall ${STAGEDIR}${PREFIX}/bin

do-install-GUI-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/heimdall-frontend ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for _f in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/${_f} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>
