# New ports collection makefile for:	leafpad
# Date created:		2004-10-18
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	leafpad
PORTVERSION=	0.7.9
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	radek@raadradd.com
COMMENT=	Light-weight GTK+ editor similar to notepad.exe

USE_GNOME=	gtk20 gnomehier desktopfileutils
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}" \
		PTHREAD_LIB="${PTHREAD_LIBS}"

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README

.if defined (WITH_NEW_SELECTOR)
EXTRA_PATCHES=	${FILESDIR}/extra-new-selector.patch
.endif

pre-everything::
.if !defined(WITH_NEW_SELECTOR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may choose to compile with unsupported patch"
	@${ECHO_MSG} "that lets leafpad use the new GTK file selector."
	@${ECHO_MSG} "Define:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_NEW_SELECTOR=yes"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/pixmaps|/gnome/pixmaps|; \
		s|/applications|/gnome/applications|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	-@update-desktop-database

.include <bsd.port.mk>
