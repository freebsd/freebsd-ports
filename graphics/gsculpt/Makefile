# ex:ts=8
# New ports collection makefile for:	gSculpt
# Date created:			Oct 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsculpt
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://gsculpt.sourceforge.net/downloads/
DISTNAME=	gSculpt-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Opensource 3D modelling application

PLIST_FILES=	bin/gsculpt
WRKSRC=		${WRKDIR}/gSculpt-${PORTVERSION}
USE_REINPLACE=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,-O3 -Wall -Werror,${CXXFLAGS},g ; \
		s,gtk-config,${GTK_CONFIG},g ; \
		s,/usr/include/glib.h,${LOCALBASE}/include/glib12/glib.h,g ; \
		s,/usr/include/gtk/,${X11BASE}/include/gtk12/gtk/,g ; \
		s,/usr/include/gdk/,${X11BASE}/include/gtk12/gdk/,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gsculpt ${PREFIX}/bin

.include <bsd.port.post.mk>
