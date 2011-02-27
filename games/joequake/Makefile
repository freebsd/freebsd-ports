# New ports collection makefile for:	joequake
# Date created:				5 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	joequake
PORTVERSION=	0.15b1329
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://runecentral.com/joequake/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-v0.15b1331-linux${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved NQ engine with ZQuake and FuhQuake graphical effects

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/src

USE_GMAKE=	yes
USE_ZIP=	yes

MAKEFILE=	Makefile.linux

OPTIONS=	GLX "Build GLX client" on \
		HUD "High quality HUD images (for OpenGL)" off \
		HUD_SA "Same for Scourge of Armagon (hipnotic)" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		X11 "Build X11 client" on \
		X86_ASM "Enable x86 assembly code" on

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GLX) && defined(WITHOUT_X11)
IGNORE=		needs at least one interface (GLX or X11)
.endif

.if !defined(WITHOUT_GLX)
USE_GL=		yes
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
ALL_TARGET+=	glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if defined(WITH_HUD)
DISTFILES+=	joequake_wad${EXTRACT_SUFX}
PLIST_SUB+=	HUD=""
.else
PLIST_SUB+=	HUD="@comment "
.endif

.if defined(WITH_HUD_SA)
DISTFILES+=	hipnotic_wad${EXTRACT_SUFX}
PLIST_SUB+=	HUD_SA=""
.else
PLIST_SUB+=	HUD_SA="@comment "
.endif

.if defined(WITH_HUD) || defined(WITH_HUD_SA)
PLIST_SUB+=	HUD_DIR=""
.else
PLIST_SUB+=	HUD_DIR="@comment "
.endif

.for f in OPTIMIZED_CFLAGS X86_ASM
.   if !defined(WITHOUT_${f})
MAKE_ENV+=	USE_${f}=YES
.   else
MAKE_ENV+=	USE_${f}=NO
.   endif
.endfor

.if !defined(WITHOUT_X11)
USE_XORG=	xxf86dga
ALL_TARGET+=	x11
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

do-install:
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/pak0.pak ${Q1DIR}/${PORTNAME}
.if !defined(WITHOUT_GLX)
	${INSTALL_PROGRAM} ${WRKSRC}/release_glx/joequake-gl.glx \
		${PREFIX}/bin/joequake-glx
.endif
.if defined(WITH_HUD) || defined(WITH_HUD_SA)
	${MKDIR} ${Q1DIR}/${PORTNAME}/textures/wad
	${INSTALL_DATA} ${WRKDIR}/wad/* ${Q1DIR}/${PORTNAME}/textures/wad
.endif
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/release_x11/joequake.x11 \
		${PREFIX}/bin/joequake-x11
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/*.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
