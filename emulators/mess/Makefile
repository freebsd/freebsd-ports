# New ports collection makefile for:	sdlmess
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	mess
PORTVERSION=	0.145
CATEGORIES=	emulators
MASTER_SITES=	http://www.mess.org/_media/downloads:/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}s
DIST_SUBDIR=	mame

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The popular MESS (Multiple Emulator Super System)

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	liberation-fonts-ttf>=0:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

OPTIONS=	BUILTIN_DEBUGGER "Enable builtin debugger support" off

ONLY_FOR_ARCHS=	i386 amd64

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_XORG=	xext xi xinerama xrender
USE_GL=		gl
USE_SDL=	sdl ttf
USE_GCC=	4.4+
USE_GMAKE=	yes
MAKE_ENV=	NOWERROR=1 OPT_FLAGS="${CXXFLAGS}" GCC_LDFLAGS="${LDFLAGS}"
MAKEFILE=	makefile
MAKE_JOBS_SAFE=	yes

CXXFLAGS+=	-fpermissive

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if defined(WITH_BUILTIN_DEBUGGER)
USE_GNOME=	gtk20 gconf2
MAKE_ENV+=	GTK_INCPATH="$$(pkg-config --cflags-only-I gtk+-2.0 gconf-2.0)" \
		GTK_CCOMFLAGS="$$(pkg-config --cflags-only-other gtk+-2.0 gconf-2.0)" \
		GTK_LIBS="$$(pkg-config --libs gtk+-2.0 gconf-2.0)"
.else
MAKE_ENV+=	NO_DEBUGGER=1 \
		GTK_INCPATH="" \
		GTK_CCOMFLAGS="" \
		GTK_LIBS=""
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAKE_ENV+=	PTR64=1
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^BUILD_EXPAT|# BUILD_EXPAT| ; \
		 s|^BUILD_ZLIB|# BUILD_ZLIB| ; \
		 /--warn-common/s|= -Wl,|= $$(GCC_LDFLAGS) -Wl,| ; \
		 s| = @gcc| := $$(CC)| ; \
		 s| = @g++| := $$(CXX)| ; \
		 s|^FULLNAME =.*|FULLNAME = $$(NAME)|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		'/-system/s|/usr/local/|${LOCALBASE}/| ; \
		 /--cflags-only-I gtk+-2.0/s|=.*|= $$(GTK_INCPATH)| ; \
		 /--cflags-only-other gtk+-2.0/s|=.*|= $$(GTK_CCOMFLAGS)| ; \
		 /--libs gtk+-2.0/s|=.*|= $$(GTK_LIBS)| ; \
		 /X11R6/s|^|#|' ${WRKSRC}/src/osd/sdl/sdl.mak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for FILE in castool chdman imgtool jedutil ldresample ldverify romcmp \
	testkeys unidasm
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/libexec/${PORTNAME}
.endfor
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} artwork ${DATADIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} hash ${DATADIR})
	@(cd ${WRKSRC}/src/osd/sdl && ${COPYTREE_SHARE} keymaps ${DATADIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mess.ini ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
