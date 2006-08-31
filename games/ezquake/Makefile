# New ports collection makefile for:	ezquake
# Date created:				29 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ezquake
PORTVERSION=	1517
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_source_${PORTVERSION}
DISTFILES=	${DISTNAME}.7z \
		${PORTNAME}_linux_${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}_linux_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Modern QuakeWorld client

EXTRACT_DEPENDS=p7zip:${PORTSDIR}/archivers/p7zip
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		pcre.0:${PORTSDIR}/devel/pcre \
		png.5:${PORTSDIR}/graphics/png \
		xmms.4:${PORTSDIR}/multimedia/xmms

USE_GCC=	3.2+
USE_GMAKE=	yes
USE_TCL=	yes
USE_TCL_BUILD=	yes
MAKE_ENV=	TCL_SUFX="${TCL_VER:S/.//}"
.for v in TCL_INCLUDEDIR TCL_LIBDIR PTHREAD_LIBS
MAKE_ENV+=	${v}="${${v}}"
.endfor
NO_WRKSUBDIR=	yes

OPTIONS=	GLX "Build GLX client" on \
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
ALL_TARGET+=	glx_release
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
ALL_TARGET+=	x11_release
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.for f in OPTIMIZED_CFLAGS X86_ASM
.   if !defined(WITHOUT_${f})
MAKE_ENV+=	USE_${f}=YES
.   else
MAKE_ENV+=	USE_${f}=NO
.   endif
.endfor

post-extract:
	@cd ${WRKDIR} && 7z x -y ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.7z \
		>/dev/null
	@${FIND} ${WRKDIR} -type d -name CVS -print0 | ${XARGS} -0 ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e 's|libtcl\.so|libtcl${TCL_VER:S/.//}|' \
		${WRKSRC}/embed_tcl.h
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' ${WRKSRC}/mp3_player.c

do-install:
	${MKDIR} ${Q1DIR}/${PORTNAME}
.for f in cfg help keymaps manual pak0.pak sb textures ../qw/*
	${CP} -R ${WRKSRC}/ezquake/${f} ${Q1DIR}/${PORTNAME}
.endfor
.if !defined(WITHOUT_GLX)
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake-gl.glx \
		${PREFIX}/bin/ezquake-glx
.endif
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake.x11 \
		${PREFIX}/bin/ezquake-x11
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
