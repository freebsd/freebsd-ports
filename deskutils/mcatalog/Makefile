# New ports collection makefile for:	mcatalog
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.17 2006/11/14 04:11:38 tmclau02 Exp $
#

PORTNAME=	mcatalog
PORTVERSION=	0.2
PORTREVISION=	10
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.mcatalog.net/releases/

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	An application for catalogue films and books

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/evolution-sharp.pc:${PORTSDIR}/mail/evolution-sharp \
		${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/evolution-sharp.pc:${PORTSDIR}/mail/evolution-sharp \
		${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20

USE_GECKO=	firefox mozilla
USE_GNOME=	gnomeprefix gnomehack gconf2 intlhack gnomesharp20
USE_SQLITE=	2
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
GCONF_SCHEMAS=	mcatalog.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/pixmaps/mcatalog|/pixmaps|g' \
		${WRKSRC}/images/Makefile.in
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${LOCALBASE}/lib/${GECKO}|g' \
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
