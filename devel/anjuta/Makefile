# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anjuta
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anjuta

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

NO_LATEST_LINK=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeprintui libgnomeui vte
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		anjuta.1 anjuta_launcher.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/pixmaps/applogo.png \
		${PREFIX}/share/gnome/anjuta/glade
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog FUTURE INSTALL NEWS README \
	doc/ScintillaDoc.html TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
