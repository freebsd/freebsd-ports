# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	bicom
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www3.sympatico.ca/mt0000/bicom/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data compressor in the PPM family

RESTRICTED=	Contact author personally regarding commercial use

NO_STAGE=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/bicom

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bicom/bicom ${PREFIX}/bin

.include <bsd.port.mk>
