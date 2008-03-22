# New ports collection makefile for:	homebank
# Date created:				24 June 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	homebank
PORTVERSION=	3.6
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Manage your personal accounts at home

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gtk20 desktopfileutils
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DOCS=		AUTHORS COPYING ChangeLog NEWS README

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@-update-desktop-database

.include <bsd.port.mk>
