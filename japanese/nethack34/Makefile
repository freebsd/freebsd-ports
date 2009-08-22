# New ports collection makefile for:	JNetHack 3.4.x
# Date created:		16 June 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	3.4.3
PORTREVISION=	5
CATEGORIES=	japanese games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-src
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
PATCH_SITE_SUBDIR=	jnethack/15876
PATCHFILES=	jnethack-${PORTVERSION}-0.7.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanized NetHack

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BISON=	build
USE_GMAKE=	yes
MAKE_ENV=	GRAPHICS="${GRAPHICS}"
PLIST_SUB=	HACKNAME="${HACKNAME}" \
		HACKDIR="${HACKDIR}" \
		HACKDOCSDIR="${HACKDOCSDIR}"

MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6
# Configure these variables as you want them to be.
HACKNAME?=	jnethack
HACKDIR?=	lib/${HACKNAME}
HACKDOCSDIR?=	share/doc/ja/nethack

.if !defined(PKGNAMESUFFIX)
USE_XORG=	xaw xpm
GRAPHICS=	X11_GRAPHICS
.else
.if ${PKGNAMESUFFIX} == "-gnome"
CATEGORIES+=	gnome
USE_GNOME=	gnomelibs
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
GRAPHICS=	GNOME_GRAPHICS
.elif ${PKGNAMESUFFIX} == "-nox11"
GRAPHICS=	# none
.elif ${PKGNAMESUFFIX} == "-qt"
USE_QT_VER=	3
MAKE_ENV+=	QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}" \
		MOC="${MOC}" LIBQT="-lqt-mt"
GRAPHICS=	QT_GRAPHICS
.endif
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
# Makefile.top digs bin/lib somehow
	${RMDIR} ${PREFIX}/bin/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${HACKDOCSDIR}
.for i in README.j ChangeLog.j INSTALL.j
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${HACKDOCSDIR}
.endfor
.endif
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${HACKDOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/${HACKDOCSDIR}
.endif

.include <bsd.port.mk>
