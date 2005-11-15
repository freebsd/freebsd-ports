# New ports collection makefile for:	mcatalog
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.9 2005/10/22 06:02:34 tmclau02 Exp $
#

PORTNAME=	mcatalog
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.mcatalog.net/releases/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	An application for catalogue films and books

BUILD_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		${X11BASE}/libdata/pkgconfig/evolution-sharp.pc:${PORTSDIR}/mail/evolution-sharp \
		${X11BASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20
LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2
RUN_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		${X11BASE}/libdata/pkgconfig/evolution-sharp.pc:${PORTSDIR}/mail/evolution-sharp \
		${X11BASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
.else
.if ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
.else
MOZILLA=	mozilla
.endif
.endif

USE_GNOME=	gnomeprefix gnomehack gconf2 intlhack
USE_GMAKE=	yes
USE_X_PREFIX=   yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
GCONF_SCHEMAS=	mcatalog.schemas

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default ${PORTNAME} uses www/mozilla for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  firefox       "
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|/pixmaps/mcatalog|/pixmaps|g' \
		${WRKSRC}/images/Makefile.in
	@${REINPLACE_CMD} -e 's|@prefix@/share|${PREFIX}/share/gnome|g' \
		${WRKSRC}/mcatalog.desktop.in
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${X11BASE}/lib/${MOZILLA}|g' \
		${WRKSRC}/src/mcatalog.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
