# New ports collection makefile for:	xskat
# Version required:	xskat-1.6
# Date created:		27 Apr 1996
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.3 1997/08/26 07:12:21 tg Exp $
#

DISTNAME=	xskat-1.6
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.germany.eu.net/pub/x11/misc/

MAINTAINER=	tg@FreeBSD.org

WRKSRC=		${WRKDIR}/xskat
USE_IMAKE=	yes

pre-configure:
	cp ${FILESDIR}/Imakefile ${WRKSRC}
	mv ${WRKSRC}/makefile ${WRKSRC}/makefile.dist

.include <bsd.port.mk>
