# New ports collection makefile for:	gview
# Version required:			0.1.4
# Date created:				30 April 1999
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	gview-0.1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.com/ResearchTriangle/Facility/1468/sg/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	gdk_imlib:${PORTSDIR}/graphics/imlib \
		gdk12:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12:${PORTSDIR}/devel/glib12 \
		gmodule12:${PORTSDIR}/devel/glib12 \
		gtk12:${PORTSDIR}/x11-toolkits/gtk12 \
		intl:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gview
.for file in AUTHORS BUGS COPYING ChangeLog NEWS README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gview
.endfor
.endif

.include <bsd.port.mk>
