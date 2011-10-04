# New ports collection makefile for:	scite
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scite
PORTVERSION=	2.29
CATEGORIES=	editors gnome
MASTER_SITES=	SF/scintilla/SciTE/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	A full-featured SCIntilla based Text Editor for GTK/GNOME

LIB_DEPENDS=	scintilla.2:${PORTSDIR}/x11-toolkits/scintilla
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USE_GMAKE=	yes
USE_GNOME=	gtk20
MAKEFILE=	makefile
MAKE_JOBS_SAFE=	yes

MAN1=		scite.1

post-patch:
	@${REINPLACE_CMD} -e 's|[(]CC[)]|(CXX)|g ; s|[(]CCOMP[)]|(CC)|g ; \
		s| -Os||g' ${WRKSRC}/makefile
.if defined(WITH_FULL_BUFFER_MENU)
	@${REINPLACE_CMD} -e 's|30, "/Buffers|props.GetInt("buffers") > 30 ? props.GetInt("buffers") - 10 : 30, "/Buffers|g' ${WRKSRC}/SciTEGTK.cxx
.endif
	@${REINPLACE_CMD} -e 's|netscape "file://$$(SciteDefaultHome)|xdg-open "file://${DOCSDIR}|' \
		${WRKSRC}/../src/SciTEGlobal.properties

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

.include <bsd.port.mk>
