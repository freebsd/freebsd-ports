# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	leafpad
PORTVERSION=	0.8.18.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	GTK+ based simple text editor

USE_GNOME=	gtk20 desktopfileutils intlhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-chooser
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README

post-extract:
	@${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	-@update-desktop-database

.include <bsd.port.mk>
