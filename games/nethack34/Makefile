# New ports collection makefile for:	nethack
# Date created:		27 March 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	3.4.3
PORTREVISION=	6
CATEGORIES?=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A dungeon explorin', slashin', hackin' game

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
MAKE_ENV=	GRAPHICS="${GRAPHICS}"
PLIST_SUB=	HACKNAME="${HACKNAME}" \
		HACKDIR="${HACKDIR}" \
		HACKDOCSDIR="${HACKDOCSDIR}"

MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

# Configure these variables as you want them to be.
HACKNAME?=	nethack
HACKDIR?=	lib/${HACKNAME}
HACKDOCSDIR?=	share/doc/${HACKNAME}

.if !defined(PKGNAMESUFFIX)
USE_XORG=	xaw xpm
GRAPHICS=	X11_GRAPHICS
.else
.if ${PKGNAMESUFFIX} == "-gnome"
MAKE_JOBS_UNSAFE=	yes
CATEGORIES=	games gnome
USE_GNOME=	gnomelibs
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
GRAPHICS=	GNOME_GRAPHICS
.elif ${PKGNAMESUFFIX} == "-nox11"
GRAPHICS=	# none
.if defined(WITH_MENUCOLORS)
PATCHFILES+=	nh343-menucolor.diff
PATCH_SITES+=	http://bilious.homelinux.org/~paxed/nethack/
PATCH_DIST_STRIP=	-p1
CFLAGS+=	-DMENU_COLOR_REGEX_POSIX
.endif
.if defined(WITH_HPMON)
PATCHFILES+=	hpmon.diff
PATCH_SITES+=	http://www.netsonic.fi/~walker/nh/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|koitsu|}
PATCH_DIST_STRIP=	-p1
CFLAGS+=	-DHPMON
.endif
.elif ${PKGNAMESUFFIX} == "-qt"
USE_QT_VER=	3
MAKE_ENV+=	QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}" \
		MOC="${MOC}" LIBQT="-lqt-mt"
GRAPHICS=	QT_GRAPHICS
.endif
.endif

.include <bsd.port.pre.mk>

pre-everything::
	@if [ "${PKGBASE}" != "nethack" ]; then \
	${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" ; \
	${ECHO_MSG} " You cannot install nethack and ${PKGBASE} in parallel   " ; \
	${ECHO_MSG} " But ${PKGBASE} reads your prior nethack scores           " ; \
	${ECHO_MSG} " Don't forget to backup your nethack libdir if it's      " ; \
	${ECHO_MSG} " important for you                                       " ; \
	${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" ; \
	fi

post-patch:
.for f in include/config.h sys/unix/Makefile.src sys/unix/Makefile.top
	@${REINPLACE_CMD} -e 's|%%HACKNAME%%|${HACKNAME}|g;s|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/win/Qt/qt_win.cpp
.if defined(WITHOUT_SHELL)
	@${REINPLACE_CMD} -e 's|#define SHELL|/* #define SHELL|' ${WRKSRC}/include/unixconf.h
.endif
.if defined(WITH_MAIL)
	@${REINPLACE_CMD} -e 's|/\* #define MAIL \*/|#define MAIL|' ${WRKSRC}/include/unixconf.h
.endif

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${HACKDOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/${HACKDOCSDIR}
.endif

.include <bsd.port.post.mk>
