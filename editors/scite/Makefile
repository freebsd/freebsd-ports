# New ports collection makefile for:	skite
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scite
PORTVERSION=	1.59
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

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
PKGNAMESUFFIX=	-gtk2
.else
USE_GNOME+=	gtk12
MAKE_ARGS=	GTK1=yes
.endif

MAN1=		scite.1

.if !defined(WITH_GTK2)
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "SciTE has the following tunable option(s):"
	@${ECHO_MSG} "	WITH_GTK2=yes		Turns on GTK-2.x support"
	@${ECHO_MSG} "	(unavailable if x11-toolkits/scintilla has been"
	@${ECHO_MSG} "	 built with GTK-1.x support)"
	@${ECHO_MSG} ""
.endif

post-patch:
	@cd ${WRKSRC} && ${MV} SciTE.desktop SciTE.desktop.pre_tr \
		&& ${TR} -d "\r" < SciTE.desktop.pre_tr > SciTE.desktop
	@${ECHO_CMD} 'Categories=Application;Development;' >> ${WRKSRC}/SciTE.desktop

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

.include <bsd.port.mk>
