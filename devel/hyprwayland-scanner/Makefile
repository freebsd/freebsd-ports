PORTNAME=	hyprwayland-scanner
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland implementation of wayland-scanner
WWW=		https://github.com/hyprwm/hyprwayland-scanner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lib pathfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

PLIST_FILES=	bin/${PORTNAME} \
		lib/cmake/${PORTNAME}/${PORTNAME}-config-version.cmake \
		lib/cmake/${PORTNAME}/${PORTNAME}-config.cmake \
		libdata/pkgconfig/${PORTNAME}.pc

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
