# New ports collection makefile for:	glade
# Version required:     0.2.3
# Date created:		29 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.1.1.1 1998/06/30 09:47:16 tg Exp $
#

DISTNAME=	glade-0.2.3
CATEGORIES=	devel
MASTER_SITES=   http://www.comp.lancs.ac.uk/~damon/builder/

MAINTAINER=     dom@myrddin.demon.co.uk

LIB_DEPENDS=	gtk\\.1\\.4:${PORTSDIR}/x11/gtk

GNU_CONFIGURE=	yes
USE_X11=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/developer.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/file_format.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/notes.txt ${PREFIX}/share/doc/glade
.endif

.include <bsd.port.mk>
