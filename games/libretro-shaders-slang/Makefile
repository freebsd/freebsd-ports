PORTNAME=	libretro-shaders-slang
DISTVERSION=	g20240719
CATEGORIES=	games

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Collection of slang shaders from libretro
WWW=		https://github.com/libretro/slang-shaders

# https://github.com/libretro/slang-shaders/issues/150
LICENSE=	GPLv1+ GPLv2+ GPLv3+ MIT PD
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	slang-shaders
GH_TAGNAME=	7d6751a

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

# DOCS files are "in-tree", therefore we must handle them in pre-install
# targets instead of the more commonly used post-install targets, and
# they must be deleted from the WRKSRC directory in any case.
pre-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${RM} ${WRKSRC}/README.md

pre-install-DOCS-off:
	${RM} ${WRKSRC}/README.md

.include <bsd.port.mk>
