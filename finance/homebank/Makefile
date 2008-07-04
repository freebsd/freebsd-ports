# New ports collection makefile for:	homebank
# Date created:				24 June 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	homebank
PORTVERSION=	3.8
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Manage your personal accounts at home

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gtk20 desktopfileutils librsvg2
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DOCS=		AUTHORS COPYING ChangeLog NEWS README

.if !defined(WITHOUT_OFX)
LIB_DEPENDS+=	ofx.4:${PORTSDIR}/finance/libofx
CONFIGURE_ARGS+=--with-ofx
.else
CONFIGURE_ARGS+=--without-ofx
.endif

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@-update-desktop-database
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
