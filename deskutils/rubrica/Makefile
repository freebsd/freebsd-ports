# New ports collection makefile for:	rubrica
# Date created:		27 February 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	rubrica
PORTVERSION=	1.0.14
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://download.berlios.de/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An addressbook for the gnome2 desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALL_TARGET=	install install-schemas

GCONF_SCHEMAS=	rubrica.schemas

post-patch:
.for file in src/dialog.c src/ui.c
	@${REINPLACE_CMD} -e 's|rub\.png|rubrica.png|g' ${WRKSRC}/${file}
.endfor
.for file in src/rubrica_type.h
	@${REINPLACE_CMD} -e '/^#include/d' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS CREDITS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in examples.rub
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
