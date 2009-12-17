# New ports collection makefile for:	shflags
# Date created:		2009-12-17
# Whom:			Yi-Jheng Lin <yzlin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shflags
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	Command-line flags module for Unix shell scripts

NO_BUILD=	yes
PLIST_FILES=	lib/shflags

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/shflags ${PREFIX}/lib

.include <bsd.port.mk>
