PORTNAME=	xNetHack
DISTVERSIONPREFIX=	xnh
DISTVERSION=	6.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	fuz@fuz.su
COMMENT=	Experimental features and improvements applied to NetHack 3.7-dev

LICENSE=	nethack
LICENSE_NAME=	NETHACK GENERAL PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/dat/license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

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
CFLAGS+=	-DX11_GRAPHICS -DUSE_TILES
GRAPHICS=	X11_GRAPHICS
.elif ${FLAVOR} == "nox11"
GRAPHICS=	# none
.endif
CFLAGS+=	-DNOMAIL -DCURSES_GRAPHICS

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
.for f in include/config.h sys/unix/Makefile.doc sys/unix/Makefile.src sys/unix/Makefile.top
	@${REINPLACE_CMD} -e 's|%%HACKNAME%%|${HACKNAME}|g' \
		-e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		${WRKSRC}/${f}
.endfor
.for f in dlb.6 nethack.6 recover.6
	@${REINPLACE_CMD} -e 's|%%HACKNAME%%|${HACKNAME}|g' \
		-e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		${WRKSRC}/doc/${f}
.endfor
.if defined(WITHOUT_SHELL)
	@${REINPLACE_CMD} -e 's|#define SHELL|/* #define SHELL|' ${WRKSRC}/include/unixconf.h
.endif
.if defined(WITH_MAIL)
	@${REINPLACE_CMD} -e 's|/\* #define MAIL \*/|#define MAIL|' ${WRKSRC}/include/unixconf.h
.endif

do-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/recover
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/${HACKNAME}
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} manpages
	@${MKDIR} ${STAGEDIR}${DATADIR}/save
	@${CP} ${WRKSRC}/sys/unix/sysconf ${STAGEDIR}/${DATADIR}/sysconf
	# Make sysconf a sample to prevent it being removed if altered
	@${CP} ${STAGEDIR}/${DATADIR}/sysconf ${STAGEDIR}/${DATADIR}/sysconf.sample
	# Make "sample" files from records to prevent them being removed
	# if they have been altered
	@${CP} ${STAGEDIR}/${DATADIR}/logfile ${STAGEDIR}/${DATADIR}/logfile.sample
	@${CP} ${STAGEDIR}/${DATADIR}/record ${STAGEDIR}/${DATADIR}/record.sample
	@${CP} ${STAGEDIR}/${DATADIR}/xlogfile ${STAGEDIR}/${DATADIR}/xlogfile.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
