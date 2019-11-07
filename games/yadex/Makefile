# Created by: Jordan DeLong <fracture@allusion.net>
# $FreeBSD$

PORTNAME=	yadex
PORTVERSION=	1.7.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://vault.101011010.xyz/distfiles/yadex/ \
		http://freebsd.nsu.ru/distfiles/yadex/ GENTOO
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	WAD file editor, for games like Doom and Heretic

LICENSE=	GPLv2

USES=		gmake perl5 shebangfix xorg
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC}" CXX="${CXX}" PREFIX="${PREFIX}"
USE_CXXSTD=	c++98	# required for 3D preview option (see r479036)
USE_PERL5=	build
SHEBANG_FILES=	scripts/copyright scripts/youngest
USE_XORG=	x11
MAKEFILE=	GNUmakefile
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	WHITE_BG 3D_RENDER SEARCH EXTRA_TOOLS LAPTOP_KEYS HEXEN DOCS
NO_OPTIONS_SORT=	yes	# required because HEXEN implies SEARCH

WHITE_BG_DESC=		Alternative (black-on-white) color scheme
3D_RENDER_DESC=		3D preview function (activate with 'R')
SEARCH_DESC=		Thing, linedef, or sector search by type
EXTRA_TOOLS_DESC=	Extra tools to Yadex' repertoire
LAPTOP_KEYS_DESC=	Key bindings for easier editing on laptops
HEXEN_DESC=		Improved Hexen support

HEXEN_IMPLIES=	SEARCH
HEXEN_PREVENTS=	LAPTOP_KEYS

PATCH_SITES=	http://glbsp.sourceforge.net/yadex/
PATCH_DIST_STRIP=	-p1 -l	# -l is needed for the Hexen patch
PATCH_PREFIX=	Yadex_${PORTVERSION:S/.//g}
PATCH_SUFFIX=	.diff
PATCHFILES=	${PATCH_PREFIX}_Depend${PATCH_SUFFIX}

3D_RENDER_PATCHFILES=	${PATCH_PREFIX}_Render3D${PATCH_SUFFIX}
3D_RENDER_PORTDOCS=	preview.html
SEARCH_PATCHFILES=	${PATCH_PREFIX}_Find${PATCH_SUFFIX}
EXTRA_TOOLS_PATCHFILES=	${PATCH_PREFIX}_Tools${PATCH_SUFFIX}
LAPTOP_KEYS_PATCHFILES=	${PATCH_PREFIX}_Keys${PATCH_SUFFIX}
HEXEN_PATCHFILES=	${PATCH_PREFIX}_Hexen${PATCH_SUFFIX}

post-patch-WHITE_BG-on:
	@${REINPLACE_CMD} -E 's,^#(CXXFLAGS \+= -DWHITE_BACKGROUND)$$,\1,' \
		${WRKSRC}/${MAKEFILE}

post-patch:
# Fix the build against Clang 6.0.0
	@${REINPLACE_CMD} -e 's,1000000ul,1000000l,' ${WRKSRC}/src/input.cc

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.[^6]* ${WRKSRC}/doc/README \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
