# New ports collection makefile for:	rubrica
# Date created:		27 February 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	rubrica
PORTVERSION=	1.0.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://digilander.libero.it/nfragale/download/rubrica/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.c1$/cr1/}

MAINTAINER=	ports@freebsd.org
COMMENT=	An addressbook for the gnome2 desktop

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.c1$/cr1/}
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"

DOC_FILES=	AUTHORS COPYING CREDITS ChangeLog INSTALL NEWS README TODO

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/examples.rub ${DOCSDIR}
.endif

.include <bsd.port.mk>
