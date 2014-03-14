# Created by: alepulver
# $FreeBSD$

PORTNAME=	joequake
PORTVERSION=	0.15b1329
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://joequake.runecentral.com/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-v0.15b1331-linux${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved NQ engine with ZQuake and FuhQuake graphical effects

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/src

USES=		gmake zip
USE_CSTD=	gnu89

MAKEFILE=	Makefile.linux

OPTIONS_MULTI=	UI
OPTIONS_MULTI_UI=	OPENGL X11
OPTIONS_DEFINE=	HUD HUD_SA OPTIMIZED_CFLAGS X86_ASM
OPTIONS_DEFAULT=	OPENGL OPTIMIZED_CFLAGS X11 X86_ASM
HUD_DESC=	High quality HUD images (for OpenGL)
HUD_SA_DESC=	Same for Scourge of Armagon (hipnotic)
X86_ASM_DESC= Enable x86 assembly code

NO_STAGE=	yes
.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
ALL_TARGET+=	glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if ${PORT_OPTIONS:MHUD}
DISTFILES+=	joequake_wad${EXTRACT_SUFX}
PLIST_SUB+=	HUD=""
.else
PLIST_SUB+=	HUD="@comment "
.endif

.if ${PORT_OPTIONS:MHUD_SA}
DISTFILES+=	hipnotic_wad${EXTRACT_SUFX}
PLIST_SUB+=	HUD_SA=""
.else
PLIST_SUB+=	HUD_SA="@comment "
.endif

.if ${PORT_OPTIONS:MHUD} || !empty(PORT_OPTIONS:MHUD_SA)
PLIST_SUB+=	HUD_DIR=""
.else
PLIST_SUB+=	HUD_DIR="@comment "
.endif

.for f in OPTIMIZED_CFLAGS X86_ASM
.   if ${PORT_OPTIONS:M${f}}
MAKE_ENV+=	USE_${f}=YES
.   else
MAKE_ENV+=	USE_${f}=NO
.   endif
.endfor

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xxf86dga
ALL_TARGET+=	x11
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

do-install:
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/pak0.pak ${Q1DIR}/${PORTNAME}
.if ${PORT_OPTIONS:MOPENGL}
	${INSTALL_PROGRAM} ${WRKSRC}/release_glx/joequake-gl.glx \
		${PREFIX}/bin/joequake-glx
.endif
.if ${PORT_OPTIONS:MHUD} || !empty(PORT_OPTIONS:MHUD_SA)
	${MKDIR} ${Q1DIR}/${PORTNAME}/textures/wad
	${INSTALL_DATA} ${WRKDIR}/wad/* ${Q1DIR}/${PORTNAME}/textures/wad
.endif
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/release_x11/joequake.x11 \
		${PREFIX}/bin/joequake-x11
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/*.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
