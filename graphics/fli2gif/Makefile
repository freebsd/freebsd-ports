# New ports collection makefile for:	fli2gif
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	fli2gif
PORTVERSION=	1.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.sco.com/skunkware/src/misc/ \
		ftp://ftp.doc.ic.ac.uk/Mirrors/ftp.sco.com/skunkware/src/misc/ \
		ftp://ftp.vse.cz/pub/.ccd0c/SCO/ftp.sco.com/skunkware/src/misc/
DISTNAME=	${PORTNAME}

MAINTAINER=	giffunip@asme.org

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fli2gif ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fli2gif
	${INSTALL_DATA}	${WRKSRC}/*.TXT ${PREFIX}/share/doc/fli2gif
	${GZIP_CMD} ${PREFIX}/share/doc/fli2gif/*.TXT
.endif

.include <bsd.port.mk>
