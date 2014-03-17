# Created by: Jordan DeLong <fracture@allusion.net>
# $FreeBSD$

PORTNAME=	yadex
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.teaser.fr/~amajorel/yadex/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	WAD file editor, for games like Doom and Hexen

LICENSE=	GPLv2

USES=		gmake perl5
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC}" CXX="${CXX}" PREFIX="${PREFIX}"
USE_PERL5=	build
USE_XORG=	x11
MAKEFILE=	GNUmakefile
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	WHITE_BG 3D_RENDER SEARCH EXTRA_TOOLS LAPTOP_KEYS DOCS

WHITE_BG_DESC=		Alternative (black-on-white) color scheme
3D_RENDER_DESC=		Build with 3D preview function
SEARCH_DESC=		Thing, linedef, or sector search by type
EXTRA_TOOLS_DESC=	Add a few extra tools to Yadex' repertoire
LAPTOP_KEYS_DESC=	Key bindings for easier editing on laptops

.include <bsd.port.options.mk>

PATCH_SITES=	http://glbsp.sourceforge.net/%SUBDIR%/
PATCH_SITE_SUBDIR=	${PORTNAME}
PATCH_DIST_STRIP=	-p1
PATCH_PREFIX=	Yadex_${PORTVERSION:S/.//g}
PATCH_SUFFIX=	.diff
PATCHFILES=	${PATCH_PREFIX}_Depend${PATCH_SUFFIX}

.if ${PORT_OPTIONS:M3D_RENDER}
PATCHFILES+=	${PATCH_PREFIX}_Render3D${PATCH_SUFFIX}
PLIST_SUB+=	3DRENDER=""
.else
PLIST_SUB+=	3DRENDER="@comment "
.endif
.if ${PORT_OPTIONS:MSEARCH}
PATCHFILES+=	${PATCH_PREFIX}_Find${PATCH_SUFFIX}
.endif
.if ${PORT_OPTIONS:MEXTRA_TOOLS}
PATCHFILES+=	${PATCH_PREFIX}_Tools${PATCH_SUFFIX}
.endif
.if ${PORT_OPTIONS:MLAPTOP_KEYS}
PATCHFILES+=	${PATCH_PREFIX}_Keys${PATCH_SUFFIX}
.endif

post-patch:
.if ${PORT_OPTIONS:MWHITE_BG}
	@${REINPLACE_CMD} -E 's,^#(CXXFLAGS \+= -DWHITE_BACKGROUND)$$,\1,' \
		${WRKSRC}/${MAKEFILE}
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.[^6]* ${WRKSRC}/doc/README \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
