# New ports collection makefile for:	gfax
# Date created:			20 January 2002
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#

PORTNAME=	gfax
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	comms print
MASTER_SITES=	http://gfax.cowlug.org/

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	A GNOME pop-up fax manager

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		${LOCALBASE}/bin/sendfax:${PORTSDIR}/comms/hylafax

USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

BASEFILES=	controller.py en.h fax-g3.profile fax.py file_handler.py \
		gfax.desktop gfax.glade gfax.png gfax.py gfax.spec \
		hfaxlib.py install.sh mgettydruid.glade prefs.py \
		prefs_ui.py setup.glade ui.py uninstall.sh

PIXFILES=	gfax.png gnome-logo-icon-transparent.png
DOCFILES=	AUTHORS COPYING Changelog HACKING INSTALL TODO

post-extract:
	@${REINPLACE_CMD} -e 's|/usr/lib/gfax|${PREFIX}/lib/gfax|g' \
		${WRKSRC}/gfax.py
	@${REINPLACE_CMD} -e 's|/usr/share/gfax|${PREFIX}/share/gfax|g ; \
		s|/usr/lib/gfax|${PREFIX}/lib/gfax|g' \
		${WRKSRC}/prefs.py

do-install:
	@${MKDIR} ${PREFIX}/lib/gfax
	@${MKDIR} ${PREFIX}/lib/gfax/pixmaps
	@${MKDIR} ${PREFIX}/share/gnome/apps/Applications
	@${MKDIR} ${PREFIX}/share/gnome/ximian
	@${MKDIR} ${PREFIX}/share/gnome/ximian/Programs
	@${MKDIR} ${PREFIX}/share/gnome/ximian/Programs/Utilities
.for base in ${BASEFILES}
	@${INSTALL_DATA} ${WRKSRC}/${base} ${PREFIX}/lib/gfax
.endfor
	@${INSTALL_SCRIPT} ${WRKSRC}/gfax.py ${PREFIX}/bin/gfax
	@${INSTALL_DATA} ${WRKSRC}/gfax.desktop ${PREFIX}/share/gnome/apps/Applications
	@${INSTALL_DATA} ${WRKSRC}/gfax.desktop ${PREFIX}/share/gnome/ximian/Programs/Utilities
	@${INSTALL_DATA} ${WRKSRC}/gfax.png ${PREFIX}/share/gnome/pixmaps
.for pixmaps in ${PIXFILES}
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/${pixmaps} ${PREFIX}/lib/gfax/pixmaps
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
