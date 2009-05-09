# New ports collection makefile for:	scite
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scite
PORTVERSION=	1.78
CATEGORIES=	editors gnome
MASTER_SITES=	SF \
		http://www.scintilla.org/
MASTER_SITE_SUBDIR=	scintilla
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	A full-featured SCIntilla based Text Editor for GTK/GNOME

LIB_DEPENDS=	scintilla.1:${PORTSDIR}/x11-toolkits/scintilla

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USE_GMAKE=	yes
USE_GNOME=	gtk20
MAKEFILE=	makefile

SUB_FILES=	pkg-message

MAN1=		scite.1

.if defined(PACKAGE_BUILDING)
IGNORE=		x11-toolkits/scintilla does not build with GTK+2 support by default
.endif

pre-configure:
	@if [ -n "`${PKG_INFO} -E 'scintilla-[0-9]*' 2> /dev/null`" ]; then \
		${ECHO_CMD} "${PKGNAME}: requires x11-toolkits/scintilla to be built with GTK+2."; \
		${FALSE}; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|[(]CC[)]|(CXX)|g ; s|gcc|$$(CC)|g ; s| -Os||g' \
		${WRKSRC}/makefile
.if defined(WITH_FULL_BUFFER_MENU)
	@${REINPLACE_CMD} -e 's|30, "/Buffers|props.GetInt("buffers") > 30 ? props.GetInt("buffers") - 10 : 30, "/Buffers|g' ${WRKSRC}/SciTEGTK.cxx
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/SciTE ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/scite.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/SciTE.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Sci48M.png ${PREFIX}/share/pixmaps
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../src/*.properties ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.jpg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.png ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
