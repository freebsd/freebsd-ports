# New ports collection makefile for:	rubrica
# Date created:		27 February 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	rubrica
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An addressbook for the GNOME 2 desktop

USE_BZIP2=	yes
USE_GNOME=	gconf2 gnomehack gnomeprefix gnometarget libglade2
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	rubrica2.schemas

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g|-Wall|g ; \
		 s|-Wmissing-prototypes -g|-Wmissing-prototypes|g ; \
		 s|@RUBRICA_FILE_|@FILE_|g'
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS CREDITS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${PREFIX}/share/doc/libRAL
	${INSTALL_DATA} ${WRKSRC}/doc/reference/html/*.* \
		${PREFIX}/share/doc/libRAL
.endif

.include <bsd.port.mk>
