PORTNAME=	omarchy-nvim
DISTVERSION=	2026.9.21
CATEGORIES=	editors

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	LazyVim based Neovim configuration from Omarchy
WWW=		https://github.com/omacom/omarchy-pkgs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		nvim:editors/neovim

USE_GITHUB=	nodefault
GH_TUPLE=	LazyVim:starter:803bc181d7c0d6d5eeba9274d9be49b287294d99:starter \
		omacom:omarchy-pkgs:3dbba7e478c7aefc7a8eda39fd79212a9bb17f66:omarchy

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKSRC_starter}

_OMARCHY_SRC=	${WRKSRC_omarchy}/pkgbuilds/omarchy-nvim

# Overlay the Omarchy customizations on the LazyVim starter before patching,
# so that files/patch-* apply to the merged configuration tree.
post-extract:
	cd ${_OMARCHY_SRC} && ${COPYTREE_SHARE} "lua plugin" ${WRKSRC}
	${CP} ${_OMARCHY_SRC}/lazyvim.json ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/config
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/config \
		"! -name *.orig"

.include <bsd.port.mk>
