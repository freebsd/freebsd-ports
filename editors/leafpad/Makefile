# New ports collection makefile for:	leafpad
# Date created:		2004-10-18
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	leafpad
PORTVERSION=	0.8.1
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
CONFIGURE_ARGS=	--enable-chooser

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README
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
