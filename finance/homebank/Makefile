# New ports collection makefile for:	homebank
# Date created:				24 June 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	homebank
PORTVERSION=	3.5
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Manage your personal accounts at home

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 desktopfileutils
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DOCS=		AUTHORS COPYING ChangeLog NEWS README

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier}!=""
USE_GNOME+=	gnomehier
PLIST_SUB+=	GNOME:=""
GNOME_ENABLED=	yes
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/application-registry|(prefix)/share/gnome/application-registry|g ; \
		s|[(]datadir[)]/mime-info|(prefix)/share/gnome/mime-info|g' \
			${WRKSRC}/mime/Makefile.in
.ifndef (GNOME_ENABLED)
	@${REINPLACE_CMD} -e 's|install-appDATA install|install|g ; \
		s| install-mimeDATA||g' \
			${WRKSRC}/mime/Makefile.in
.endif

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@-update-desktop-database

.include <bsd.port.post.mk>
