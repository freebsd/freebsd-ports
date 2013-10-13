# Created by: asami
# $FreeBSD$

PORTNAME=	nethack
PORTVERSION=	3.3.1
PORTREVISION=	10
CATEGORIES?=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER?=	glewis@FreeBSD.org
COMMENT?=	A dungeon explorin', slashin', hackin' game

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LATEST_LINK=	nethack33${PKGNAMESUFFIX}

USE_GMAKE=	yes
MAKE_ENV=	GRAPHICS="${GRAPHICS}"
PLIST_SUB=	HACKNAME="${HACKNAME}" \
		HACKEXT="${HACKEXT}"
MAKE_JOBS_UNSAFE=	yes

MAN6=		dgn_comp${HACKEXT}.6 dlb${HACKEXT}.6 lev_comp${HACKEXT}.6 \
		${HACKNAME}.6 recover${HACKEXT}.6

HACKEXT?=       33
HACKNAME?=      ${PORTNAME}${HACKEXT}
HACKDIR?=       share/${HACKNAME}
HACKLINK=       nethack

DATADIR=        ${PREFIX}/${HACKDIR}
DOCSDIR=        ${PREFIX}/share/doc/${HACKNAME}
PKGDEINSTALL=   ${WRKDIR}/pkg-deinstall

.if !defined(PKGNAMESUFFIX)
USE_XORG=	xaw xpm
GRAPHICS=	X11_GRAPHICS
.else
.if ${PKGNAMESUFFIX} == "-nox11"
GRAPHICS=	# none
.endif
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.include <bsd.port.options.mk>

.if !exists(${PREFIX}/bin/${HACKLINK}) && ${HACKNAME} != ${HACKLINK}
PLIST_SUB+=	HACKLINK=""
.else
PLIST_SUB+=	HACKLINK="@comment "
.endif

pre-everything::
.if defined(WITH_TTY_GRAPHICS) || defined(WITHOUT_X11)
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} " You cannot install nethack and ${PKGBASE} in parallel   "
	@${ECHO_MSG} " But ${PKGBASE} read your prior nethack scores           "
	@${ECHO_MSG} " Don't forget to backup your nethack libdir if it's      "
	@${ECHO_MSG} " important for you                                       "
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
.else
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} " You may use the following build options:                "
	@${ECHO_MSG} " WITH_TTY_GRAPHICS=yes              build with no GUI    "
	@${ECHO_MSG} " WITHOUT_X11=yes                    same as above        "
	@${ECHO_MSG} "                                                         "
	@${ECHO_MSG} " By default, nethack port is built with X11 GUI.         "
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/win/Qt/qt_win.cpp

pre-configure:
.for f in include/config.h sys/unix/Makefile.top sys/unix/Makefile.doc
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
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

pre-install:
	@${CAT} ${FILESDIR}/pkg-deinstall.in | ${SED} \
		-e 's|%%HACKDIR%%|${HACKDIR}|g' > ${PKGDEINSTALL}

post-install:
.if !exists(${PREFIX}/bin/${HACKLINK}) && ${HACKNAME} != ${HACKLINK}
	@${LN} -s -f ${PREFIX}/bin/${HACKNAME} ${PREFIX}/bin/${HACKLINK}
.endif
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} manpages
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
