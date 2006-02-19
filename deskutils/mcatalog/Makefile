# New ports collection makefile for:	mcatalog
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.12 2006/01/11 00:29:46 tmclau02 Exp $
#

PORTNAME=	mcatalog
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.mcatalog.net/releases/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	An application for catalogue films and books

BUILD_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		${X11BASE}/libdata/pkgconfig/evolution-sharp.pc:${PORTSDIR}/mail/evolution-sharp \
		${X11BASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20
RUN_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		${X11BASE}/libdata/pkgconfig/evolution-sharp.pc:${PORTSDIR}/mail/evolution-sharp \
		${X11BASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20

USE_GECKO=	mozilla firefox
USE_GNOME=	gnomeprefix gnomehack gconf2 intlhack
USE_SQLITE=	2
USE_GMAKE=	yes
USE_X_PREFIX=   yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
GCONF_SCHEMAS=	mcatalog.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/pixmaps/mcatalog|/pixmaps|g' \
		${WRKSRC}/images/Makefile.in
	@${REINPLACE_CMD} -e 's|@prefix@/share|${PREFIX}/share/gnome|g' \
		${WRKSRC}/mcatalog.desktop.in
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${X11BASE}/lib/${GECKO}|g' \
		${WRKSRC}/src/mcatalog.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
