# ex:ts=8
# Ports collection makefile for:	g3dviewer
# Date created:			May 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	g3dviewer
PORTVERSION=	0.1.0
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://automagically.de/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D file viewer for GTK+

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_GNOME=	gtk20 pkgconfig
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
