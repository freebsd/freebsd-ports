# New ports collection makefile for:	nethack
# Date created:		27 March 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	3.3.1
PORTREVISION=	3
CATEGORIES?=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nethack
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A dungeon explorin', slashin', hackin' game

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_LATEST_LINK=	yes

USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ENV=	CXX="${CXX}" GRAPHICS="${GRAPHICS}" LDFLAGS="${LDFLAGS}"

MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

.if defined(WITH_GNOME_GRAPHICS)
CATEGORIES=	games gnome
PKGNAMESUFFIX=	-gnome
USE_GETOPT_LONG=yes
USE_GNOME=	yes
GRAPHICS=	GNOME_GRAPHICS
.elif defined(WITH_QT_GRAPHICS)
PKGNAMESUFFIX=	-qt
USE_QT_VER=	2
MAKE_ENV+=	QTCPPFLAGS="${QTCPPFLAGS}" QTCFGLIBS="${QTCFGLIBS}" \
		MOC="${MOC}" LIBQT="-l${QTNAME}"
GRAPHICS=	QT_GRAPHICS
.elif defined(WITH_TTY_GRAPHICS) || defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
.else
USE_XPM=	yes
GRAPHICS=	X11_GRAPHICS
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_QT_GRAPHICS) && ${OSVERSION} >= 500113
BROKEN=		"Does not build"
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
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
