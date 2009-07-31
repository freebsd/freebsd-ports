# New ports collection makefile for:	nethack
# Date created:		27 March 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	3.3.1
PORTREVISION=	9
CATEGORIES?=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nethack
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER?=	glewis@FreeBSD.org
COMMENT?=	A dungeon explorin', slashin', hackin' game

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LATEST_LINK=	nethack33${PKGNAMESUFFIX}

USE_GMAKE=	yes
MAKE_ENV=	GRAPHICS="${GRAPHICS}" LDFLAGS="${LDFLAGS}"
PLIST_SUB=	HACKNAME="${HACKNAME}" \
		HACKEXT="${HACKEXT}"

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
.if ${PKGNAMESUFFIX} == "-gnome"
CATEGORIES=	games gnome
USE_GNOME=	gnomelibs
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
GRAPHICS=	GNOME_GRAPHICS
.elif ${PKGNAMESUFFIX} == "-nox11"
GRAPHICS=	# none
.elif ${PKGNAMESUFFIX} == "-qt"
USE_QT_VER=	2
MAKE_ENV+=	QTCPPFLAGS="${QTCPPFLAGS}" QTCFGLIBS="${QTCFGLIBS}" \
		MOC="${MOC}" LIBQT="-l${QTNAME}"
GRAPHICS=	QT_GRAPHICS
.endif
.endif

.include <bsd.port.pre.mk>

.if !exists(${PREFIX}/bin/${HACKLINK}) && ${HACKNAME} != ${HACKLINK}
PLIST_SUB+=	HACKLINK=""
.else
PLIST_SUB+=	HACKLINK="@comment "
.endif

pre-everything::
.if defined(WITH_GNOME_GRAPHICS) || defined(WITH_QT_GRAPHICS) \
		|| defined(WITH_TTY_GRAPHICS) || defined(WITHOUT_X11)
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} " You cannot install nethack and ${PKGBASE} in parallel   "
	@${ECHO_MSG} " But ${PKGBASE} read your prior nethack scores           "
	@${ECHO_MSG} " Don't forget to backup your nethack libdir if it's      "
	@${ECHO_MSG} " important for you                                       "
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
.else
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} " You may use the following build options:                "
	@${ECHO_MSG} " WITH_GNOME_GRAPHICS=yes            build with GNOME GUI "
	@${ECHO_MSG} " WITH_QT_GRAPHICS=yes               build with Qt GUI    "
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
