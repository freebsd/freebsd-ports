# New ports collection makefile for:	mcatalog
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mcatalog
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mcatalog

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	An application for catalogue films and books

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp
LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnomeprefix gnomehack gconf2
USE_GMAKE=	yes
USE_X_PREFIX=   yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
GCONF_SCHEMAS=	mcatalog.schemas

BROKEN="doesn't build with Mono 1.1.7 yet"

post-patch:
	@${REINPLACE_CMD} -e 's|/pixmaps/mcatalog|/pixmaps|g' \
		${WRKSRC}/images/Makefile.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
