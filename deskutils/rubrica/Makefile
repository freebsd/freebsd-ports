# New ports collection makefile for:	rubrica
# Date created:		27 February 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	rubrica
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://digilander.libero.it/nfragale/download/rubrica/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An addressbook for the gnome2 desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libgnomeui
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CFLAGS.*$$|CFLAGS = @CFLAGS@|g ; \
		 s|^rubricadocdir.*$$|rubricadocdir =|g ; \
		 s|$$(rubricadoc_DATA)||g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in CREDITS examples.rub
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
