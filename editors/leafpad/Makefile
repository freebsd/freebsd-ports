# New ports collection makefile for:	leafpad
# Date created:		2004-10-18
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	leafpad
PORTVERSION=	0.7.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	radek@raadradd.com
COMMENT=	Light-weight GTK+ Editor similar to notepad.exe

USE_GNOME=	gtk20 gnomehier
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

DOCS=		AUTHORS COPYING ChangeLog INSTALL README

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-nls \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}
PLIST_SUB+=	NLS:=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/pixmaps|/gnome/pixmaps|; \
		s|/applications|/gnome/applications|' \
			${WRKSRC}/Makefile.in ${WRKSRC}/src/Makefile.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
