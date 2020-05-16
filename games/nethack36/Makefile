# Created by: asami
# $FreeBSD$

PORTNAME=	nethack36
PORTVERSION=	3.6.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://nethack.org/download/${PORTVERSION}/
DISTNAME=	${TRUEPORTNAME}-${PORTVERSION:S/.//g}-src

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dungeon explorin', slashin', hackin' game

LICENSE=	nethack
LICENSE_NAME=	NETHACK GENERAL PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/dat/license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		alias compiler:c11 gmake ncurses tar:tgz

WRKSRC=		${WRKDIR}/NetHack-NetHack-${PORTVERSION}_Released

MAKE_ENV=	GRAPHICS="${GRAPHICS}"
PLIST_SUB=	HACKNAME="${HACKNAME}" \
		HACKEXT="${HACKEXT}"
TRUEPORTNAME=	nethack

# Configure these variables as you want them to be.
HACKEXT?=	36
HACKNAME?=	${TRUEPORTNAME}${HACKEXT}
HACKDIR?=	share/${HACKNAME}
HACKLINK=	${TRUEPORTNAME}

DATADIR=	${PREFIX}/${HACKDIR}
DOCSDIR=	${PREFIX}/share/doc/${HACKNAME}
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

.if !defined(PKGNAMESUFFIX)
USES+=		xorg
USE_XORG=	xaw xpm xmu xext xt x11 sm ice
CFLAGS+=	-DX11_GRAPHICS -DUSE_TILES
GRAPHICS=	X11_GRAPHICS
.else
.if ${PKGNAMESUFFIX} == "-nox11"
GRAPHICS=	# none
.endif
.endif
CFLAGS+=	-DNOMAIL -DCURSES_GRAPHICS

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if !exists(${PREFIX}/bin/${HACKLINK}) && ${HACKNAME} != ${HACKLINK}
PLIST_SUB+=	HACKLINK=""
.else
PLIST_SUB+=	HACKLINK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/win/Qt/qt_win.cpp
.for f in sys/unix/Makefile.doc sys/unix/Makefile.src sys/unix/Makefile.top
	@${REINPLACE_CMD} -e 's|%%HACKNAME%%|${HACKNAME}|g' \
		-e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		-e 's|%%HACKEXT%%|${HACKEXT}|g' \
		${WRKSRC}/${f}
.endfor
.for f in dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6
	@${REINPLACE_CMD} -e 's|%%HACKNAME%%|${HACKNAME}|g' \
		-e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		-e 's|%%HACKEXT%%|${HACKEXT}|g' \
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

pre-install:
	@${CAT} ${FILESDIR}/pkg-deinstall.in | ${SED} \
		-e 's|%%HACKDIR%%|${HACKDIR}|g' > ${PKGDEINSTALL}

post-install:
.if !exists(${PREFIX}/bin/${HACKLINK}) && ${HACKNAME} != ${HACKLINK}
	@${LN} -s -f ${PREFIX}/bin/${HACKNAME} ${STAGEDIR}${PREFIX}/bin/${HACKLINK}
.endif
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
