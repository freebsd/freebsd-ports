# New ports collection makefile for:	leafpad
# Date created:				2004-10-18
# Whom:					Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	leafpad
PORTVERSION=	0.8.9
PORTREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	radek@raadradd.com
COMMENT=	GTK+ based simple text editor

USE_GNOME=	gtk20 desktopfileutils intlhack
USE_GETTEXT=	YES
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		PTHREAD_LIB="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-chooser

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
