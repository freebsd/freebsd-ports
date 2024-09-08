PORTNAME=	libretro-shaders-slang
DISTVERSION=	g20240823
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
GH_TAGNAME=	0cededf

DATADIR=	${PREFIX}/share/libretro/shaders/shaders_slang
EXTRACT_AFTER_ARGS=	--exclude ".gitlab-ci.yml" --exclude "configure" \
			--exclude "Makefile" --no-same-owner \
			--no-same-permissions
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -regex ^./README.md")

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
