# New ports collection makefile for:	atlast
# Date created:         26 Ag 97
# Whom:                 Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	atlast
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.fourmilab.ch/atlast/ \
		http://www.fourmilab.to/atlast/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Autodesk Threaded Language Application System Toolkit

MAKE_ARGS=	CFLAGS="${CFLAGS} -DMEMSTAT -DALIGNMENT -DEXPORT -DNOMEMCHECK"

PLIST_FILES=	bin/atlast
PORTDOCS=	atlast.ps atlast.rtf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/atlast ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/atlast.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/atlast.rtf ${DOCSDIR}
.endif

.include <bsd.port.mk>
