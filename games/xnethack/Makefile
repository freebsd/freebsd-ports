PORTNAME=	xNetHack
DISTVERSIONPREFIX=	xnh
DISTVERSION=	7.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	fuz@fuz.su
COMMENT=	Experimental features and improvements applied to NetHack 3.7-dev

LICENSE=	nethack
LICENSE_NAME=	NETHACK GENERAL PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/dat/license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FLAVORS=	x11 nox11 qt
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11
qt_PKGNAMESUFFIX=	-qt

USES=		alias compiler:c11 gmake ncurses tar:tgz lua:54
USE_GITHUB=	yes
GH_ACCOUNT=	copperwater

MAKE_ENV=	GRAPHICS="${GRAPHICS}"
PLIST_SUB=	HACKNAME="${HACKNAME}"

# Configure these variables as you want them to be.
HACKNAME?=	${PORTNAME:tl}
HACKDIR?=	share/${HACKNAME}

DATADIR=	${PREFIX}/${HACKDIR}
DOCSDIR=	${PREFIX}/share/doc/${HACKNAME}

.if ${FLAVOR} == "x11"
USES+=		xorg
USE_XORG=	xaw xpm xmu xext xt x11 sm ice
CFLAGS+=	-DUSE_TILES
GRAPHICS=	X11_GRAPHICS
.elif ${FLAVOR} == "nox11"
GRAPHICS=	# none
.elif ${FLAVOR} == "qt"
USES+=		localbase pkgconfig qt:5
USE_QT=		buildtools_build core gui multimedia network widgets
MAKE_ENV+=	MOCPATH=${MOC} LINK="${CXX} -pie"
# Qt wants PIC for some reason.  For C code, PIE should be enough.
CFLAGS+=	-I${QT_INCDIR} -fpie
CXXFLAGS+=	-I${QT_INCDIR} -fpic
GRAPHICS=	QT_GRAPHICS
.endif

CFLAGS+=	-DNOMAIL -DCURSES_GRAPHICS

# nhlua.c has a (patched out) version check for lua when the sandbox
# is used.  As I cannot ascertain whether using the system's different
# lua version could cause problems, I'll leave the sandbox disabled by
# default.
OPTIONS_DEFINE=	DOCS SANDBOX
SANDBOX_DESC=	Run lua in a sandbox (untested)
SANDBOX_CFLAGS=	-DNHL_SANDBOX

.include <bsd.port.pre.mk>

post-patch:
.for f in include/config.h sys/unix/Makefile.doc sys/unix/Makefile.src sys/unix/Makefile.top
	@${REINPLACE_CMD} -e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		${WRKSRC}/${f}
.endfor
.for f in dlb.6 nethack.6 recover.6
	@${REINPLACE_CMD} -e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		${WRKSRC}/doc/${f}
.endfor
.if defined(WITHOUT_SHELL)
	@${REINPLACE_CMD} -e 's|#define SHELL|/* #define SHELL|' ${WRKSRC}/include/unixconf.h
.endif
.if defined(WITH_MAIL)
	@${REINPLACE_CMD} -e 's|/\* #define MAIL \*/|#define MAIL|' ${WRKSRC}/include/unixconf.h
.endif

do-configure:
	${TOUCH} ${WRKSRC}/dat/gitinfo.txt
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/recover
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/${HACKNAME}
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} manpages
	${MKDIR} ${STAGEDIR}${DATADIR}/save
	${CP} ${WRKSRC}/sys/unix/sysconf ${STAGEDIR}/${DATADIR}/sysconf
.for f in livelog logfile record sysconf xlogfile
	${CP} ${STAGEDIR}/${DATADIR}/${f} ${STAGEDIR}/${DATADIR}/${f}.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
