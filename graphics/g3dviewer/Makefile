# ex:ts=8
# Ports collection makefile for:	g3dviewer
# Date created:			May 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	g3dviewer
PORTVERSION=	0.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://automagically.de/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D file viewer for GTK+

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_GNOME=	gnometarget gtk20
USE_GL=		yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		g3dviewer.1

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|DBG_CFLAGS="-O2"|DBG_CFLAGS=""|g ; \
		 s|$$datadir/$$PACKAGE/|$$libdir/$$PACKAGE/|g' ${WRKSRC}/configure
.for file in plugins/image/Makefile.in plugins/import/Makefile.in
	@${REINPLACE_CMD} -e 's|= $$(pkgdatadir)|= $$(pkglibdir)|g ; \
		 s|= -Wall|= -fPIC -Wall|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
