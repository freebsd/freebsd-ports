# New ports collection makefile for:	skite
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scite
PORTVERSION=	1.55
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
MAKEFILE=	makefile
USE_REINPLACE=	yes
PLIST_SUB=	GNOME_COMMENT=${GNOME_COMMENT}

.if defined(WITH_GNOME)
USE_GNOME=	gtk20 gnomeprefix
PKGNAMESUFFIX=	-gnome
GNOME_COMMENT=	''
.elif defined(WITH_GTK2)
USE_GNOME=	gtk20
PKGNAMESUFFIX=	-gtk2
.else
USE_GNOME=	gtk12
MAKE_ARGS=	GTK1=yes
.endif
GNOME_COMMENT?=	'@comment '

post-patch:
	@${REINPLACE_CMD} -e 's,$$(CC),$$(CXX),g' ${WRKSRC}/makefile
.if defined(WITH_GNOME)
	@${TR} -d "\r" < ${WRKSRC}/SciTE.desktop > ${WRKDIR}/SciTE.desktop
	@${ECHO_CMD} 'Categories=Application;Development;' >> ${WRKDIR}/SciTE.desktop
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/SciTE ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/scite.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../src/*.properties ${DATADIR}
.if defined(WITH_GNOME)
	${INSTALL_DATA} ${WRKDIR}/SciTE.desktop ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/Sci48M.png ${PREFIX}/share/gnome/pixmaps
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.jpg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
