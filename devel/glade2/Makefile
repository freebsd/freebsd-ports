# New ports collection makefile for:	glade
# Version required:     0.3.7
# Date created:		29 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.10 1998/11/18 17:35:16 vanilla Exp $
#

DISTNAME=	glade-0.3.7
CATEGORIES=	devel
MASTER_SITES=   http://glade.pn.org/

MAINTAINER=     dom@myrddin.demon.co.uk

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk11-config"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/developer.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/file_format.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/generic.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/notes.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/portability.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/source_code.txt ${PREFIX}/share/doc/glade
.endif

.include <bsd.port.mk>
