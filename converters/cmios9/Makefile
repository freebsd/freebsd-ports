# New ports collection makefile for:   cmios9
# Date created:                7 June 2003
# Whom:                        M.Indlekofer@gmx.de
#
# $FreeBSD$
#

PORTNAME=      cmios9
PORTVERSION=   1.6
CATEGORIES=    converters
MASTER_SITES=  http://www.spies.com/~kmi/

MAINTAINER=    M.Indlekofer@gmx.de
COMMENT=       Ftp-like access to Fairlight OS9/MDR-DOS devices and image files
PLIST_FILES=	bin/cmios9
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin	

.include <bsd.port.mk>
