# New ports collection makefile for:	skite
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scite
PORTVERSION=	1.62
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.scintilla.org/
MASTER_SITE_SUBDIR=	scintilla
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-featured SCIntilla based Text Editor for GTK/GNOME

LIB_DEPENDS=	scintilla.1:${PORTSDIR}/x11-toolkits/scintilla

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier
MAKEFILE=	makefile
MAKE_ENV=	CC="${CXX}"
EXTRA_PATCH_FILES=	lua/include/lauxlib.h \
			lua/include/lua.h \
			lua/src/lobject.h \
			lua/src/lzio.h \
			lua/src/ltm.h \
			lua/src/lopcodes.c \
			lua/src/lopcodes.h \
			lua/src/lstate.c \
			lua/src/lstate.h \
			lua/src/ldo.h \
			lua/src/lmem.h \
			lua/src/lgc.h \
			lua/src/lgc.c \
			lua/src/lvm.h \
			lua/src/lstring.h \
			lua/src/ldo.c \
			lua/src/lfunc.c \
			lua/src/llex.h \
			lua/src/llex.c \
			lua/src/lparser.c \
			lua/src/lib/lauxlib.c

OPTIONS=	GTK2 "Turns on GTK-2.x support (Default is GTK-1)" off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
PKGNAMESUFFIX=	-gtk2
.else
USE_GNOME+=	gtk12
MAKE_ARGS=	GTK1=yes
.endif

MAN1=		scite.1

post-patch:
	@cd ${WRKSRC} && ${MV} SciTE.desktop SciTE.desktop.pre_tr \
		&& ${TR} -d "\r" < SciTE.desktop.pre_tr > SciTE.desktop
	@${ECHO_CMD} 'Categories=Application;Development;' >> ${WRKSRC}/SciTE.desktop
# deal with dos end-of-line symbols break build with gcc 2.95.
.for file in ${EXTRA_PATCH_FILES}
	@${CP} ${WRKSRC}/../${file} \
		${WRKSRC}/../${file}.orig
	@/usr/bin/col < ${WRKSRC}/../${file}.orig \
		> ${WRKSRC}/../${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/SciTE ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/scite.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/SciTE.desktop ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/Sci48M.png ${PREFIX}/share/gnome/pixmaps
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.jpg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.png ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../src/*.properties ${DATADIR}

.include <bsd.port.post.mk>
