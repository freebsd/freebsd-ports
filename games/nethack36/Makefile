# Created by: asami
# $FreeBSD$

PORTNAME=	nethack36
PORTVERSION=	3.6.0
PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	SF/${TRUEPORTNAME}/${TRUEPORTNAME}/${PORTVERSION}
DISTNAME=	${TRUEPORTNAME}-${PORTVERSION:S/.//g}-src

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dungeon explorin', slashin', hackin' game

LICENSE=	nethack
LICENSE_NAME=	NETHACK GENERAL PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/dat/license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/${TRUEPORTNAME}-${PORTVERSION}

USES=		gmake tar:tgz
MAKE_ENV=	GRAPHICS="${GRAPHICS}"
PLIST_SUB=	HACKNAME="${HACKNAME}" \
		HACKEXT="${HACKEXT}"
MAKE_JOBS_UNSAFE=	yes
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
USE_XORG=	xaw xpm
CFLAGS+=	-DX11_GRAPHICS -DUSE_TILES
GRAPHICS=	X11_GRAPHICS
.else
.if ${PKGNAMESUFFIX} == "-nox11"
GRAPHICS=	# none
.endif
.endif
CFLAGS+=	-DNOMAIL

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.include <bsd.port.options.mk>

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
.for f in include/config.h sys/unix/Makefile.doc sys/unix/Makefile.src sys/unix/Makefile.top
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
	@${CP} ${WRKSRC}/sys/unix/sysconf ${STAGEDIR}${DATADIR}/sysconf
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
