# New ports collection makefile for:	leafpad
# Date created:				2004-10-18
# Whom:					Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	leafpad
PORTVERSION=	0.8.16
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	radek@raadradd.com
COMMENT=	GTK+ based simple text editor

USE_GNOME=	gtk20 desktopfileutils intlhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-chooser
INSTALLS_ICONS=	yes
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	-@update-desktop-database

.include <bsd.port.mk>
