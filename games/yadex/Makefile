# New ports collection makefile for:	Yadex
# Date created:				17 June 2001
# Whom:					Jordan DeLong <fracture@allusion.net>
#
# $FreeBSD$
#

PORTNAME=	yadex
PORTVERSION=	1.7.0
CATEGORIES=	games
MASTER_SITES=	http://www.teaser.fr/~amajorel/yadex/ \
		http://hjem.get2net.dk/RasII/amajorel/yadex/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A WAD-file editor, for games like Doom and Hexen

BROKEN=		Does not build

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC}" CXX="${CXX}" PREFIX="${PREFIX}"

MAN6=		yadex.6

OPTIONS=	WHITE_BG "Use alternative (black-on-white) color scheme" off \
		3D_RENDER "Build with a 3D preview function" off \
		SEARCH "Search for a thing, linedef or sector by type" off \
		EXTRA_TOOLS "Add a few extra tools to Yadex's repertoire" off \
		LAPTOP_KEYS "Key bindings to make editing easier on laptops" off

.include <bsd.port.pre.mk>

PATCH_SITES=	http://glbsp.sourceforge.net/%SUBDIR%/
PATCH_SITE_SUBDIR=	${PORTNAME}
PATCH_DIST_STRIP=	-p1
PATCH_PREFIX=	${PORTNAME:U:C/^(.).*$/\1/g}${PORTNAME:C/^(.)//}_${PORTVERSION:S/.//g}
PATCH_SUFFIX=	.diff
PATCHFILES=	${PATCH_PREFIX}_Depend${PATCH_SUFFIX}

.if defined(WITH_3D_RENDER) || defined(WITH_SEARCH) \
	|| defined(WITH_EXTRA_TOOLS) || defined(WITH_LAPTOP_KEYS)
. if defined(WITH_3D_RENDER)
PATCHFILES+=	${PATCH_PREFIX}_Render3D${PATCH_SUFFIX}
PLIST_SUB+=	3DRENDER=""
. else
PLIST_SUB+=	3DRENDER="@comment "
. endif
. if defined(WITH_SEARCH)
PATCHFILES+=	${PATCH_PREFIX}_Find${PATCH_SUFFIX}
. endif
. if defined(WITH_EXTRA_TOOLS)
PATCHFILES+=	${PATCH_PREFIX}_Tools${PATCH_SUFFIX}
. endif
. if defined(WITH_LAPTOP_KEYS)
PATCHFILES+=	${PATCH_PREFIX}_Keys${PATCH_SUFFIX}
. endif
.else
PLIST_SUB+=	3DRENDER="@comment "
.endif

.if defined(WITH_WHITE_BG)
post-patch:
	@${REINPLACE_CMD} -E 's,^#(CXXFLAGS \+= -DWHITE_BACKGROUND)$$,\1,' \
		${WRKSRC}/${MAKEFILE}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.[^6]* ${WRKSRC}/doc/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
