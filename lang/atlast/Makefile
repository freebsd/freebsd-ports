# New ports collection makefile for:	atlast
# Date created:         26 Ag 97
# Whom:                 Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	atlast
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	http://www.fourmilab.ch/atlast/ \
		http://www.fourmilab.to/atlast/

MAINTAINER=	giffunip@asme.org

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/atlast $(PREFIX)/bin

post-install:
	strip ${PREFIX}/bin/atlast
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/atlast
	${INSTALL_DATA} ${WRKSRC}/atlast.ps ${PREFIX}/share/doc/atlast
	${INSTALL_DATA} ${WRKSRC}/atlast.rtf ${PREFIX}/share/doc/atlast
.endif

.include <bsd.port.mk>
