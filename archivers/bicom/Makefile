# New ports collection makefile for:	bicom
# Date created:				09 May 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	bicom
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www3.sympatico.ca/mt0000/bicom/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}101

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Data compressor in the PPM family

RESTRICTED=	"Contact author personally regarding commercial use"

NO_WRKSUBDIR=	yes
MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/bicom
USE_ZIP=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bicom/bicom ${PREFIX}/bin

.include <bsd.port.mk>
