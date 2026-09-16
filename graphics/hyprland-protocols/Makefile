PORTNAME=	hyprland-protocols
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	graphics

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Wayland protocol extensions for Hyprland
WWW=		https://github.com/hyprwm/hyprland-protocols

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

STRIP=		# empty
NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
