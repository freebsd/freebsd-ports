# New ports collection makefile for:	libungif
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libungif
PORTVERSION=	4.1.0b1
CATEGORIES=	graphics
MASTER_SITES=	ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

DOCDIR=		${PREFIX}/share/doc/libungif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UNCOMPRESSED_GIF ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCDIR}
.endif

.include <bsd.port.mk>
