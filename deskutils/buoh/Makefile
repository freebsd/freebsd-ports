# New ports collection makefile for:	buoh
# Date created:				10 November 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buoh
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	deskutils www gnome
MASTER_SITES=	http://buoh.steve-o.org/downloads/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A reader for online strips comics

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
GCONF_SCHEMAS=	buoh.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]datadir[)]/applications|${X11BASE}/share/applications|g' \
		${WRKSRC}/data/Makefile.in

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${LN} -sf ${DATADIR}/pixmaps/buoh64x64.png \
		${X11BASE}/share/pixmaps/buoh64x64.png

.include <bsd.port.mk>
