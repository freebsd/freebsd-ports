# New ports collection makefile for:	nethack
# Date created:		27 March 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	3.4.0
CATEGORIES?=	games
MASTER_SITES=	ftp://ftp.nethack.org/pub/nethack/nh${PORTVERSION:S/.//g}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER?=	dscheidt@enteract.com

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" GRAPHICS="${GRAPHICS}"
PLIST_SUB=	HACKNAME="${HACKNAME}" \
		HACKDIR="${HACKDIR}" \
		HACKDOCSDIR="${HACKDOCSDIR}"

MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

# Configure these variables as you want them to be.
HACKNAME?=	nethack
HACKDIR?=	lib/${HACKNAME}
HACKDOCSDIR?=	share/doc/${HACKNAME}

.if defined(WITH_GNOME_GRAPHICS)
CATEGORIES=	games gnome
PKGNAMESUFFIX=	-gnome
LIB_DEPENDS+=	gnugetopt:${PORTSDIR}/devel/libgnugetopt
USE_GNOME=	yes
GRAPHICS=	GNOME_GRAPHICS
.elif defined(WITH_QT_GRAPHICS)
PORTREVISION=	1
PKGNAMESUFFIX=	-qt
USE_QT_VER=	3
MAKE_ENV+=	QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}" \
		MOC="${MOC}" LIBQT="-lqt-mt"
GRAPHICS=	QT_GRAPHICS
.elif defined(WITH_TTY_GRAPHICS) || defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
.else
USE_XPM=	yes
GRAPHICS=	X11_GRAPHICS
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
.for f in include/config.h sys/unix/Makefile.src sys/unix/Makefile.top
	${REINPLACE_CMD} -e 's|%%HACKNAME%%|${HACKNAME}|g;s|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' ${WRKSRC}/${f}
.endfor
	${REINPLACE_CMD} -e 's|<regex.h>|<gnuregex.h>|g' ${WRKSRC}/src/sounds.c
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/win/Qt/qt_win.cpp
.if defined(WITHOUT_SHELL)
	@${REINPLACE_CMD} -e 's|#define SHELL|/* #define SHELL|' ${WRKSRC}/include/unixconf.h
.endif

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${HACKDOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/${HACKDOCSDIR}
.endif

.include <bsd.port.mk>
