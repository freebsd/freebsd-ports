# New ports collection makefile for:	fli2gif
# Version required:	1.1
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

DISTNAME=       fli2gif
PKGNAME=	fli2gif-1.1
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.sco.com/skunkware/src/misc/ \
		ftp://ftp.doc.ic.ac.uk/Mirrors/ftp.sco.com/skunkware/src/misc/ \
		ftp://ftp.vse.cz/pub/.ccd0c/SCO/ftp.sco.com/skunkware/src/misc/

MAINTAINER=     giffunip@asme.org

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fli2gif ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fli2gif
	${INSTALL_DATA}	${WRKSRC}/*.TXT ${PREFIX}/share/doc/fli2gif
	${GZIP_CMD} ${PREFIX}/share/doc/fli2gif/*.TXT
.endif

.include <bsd.port.mk>
