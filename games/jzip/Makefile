# New ports collection makefile for:	jzip
# Version required:			2.0.1g
# Date created:				7 May 1998
# Whom:					Matthew Hunt <mph@FreeBSD.org>
#
# $Id$
#

DISTNAME=		jzip201g
PKGNAME=		jzip-2.0.1g
CATEGORIES=		games
MASTER_SITES=   	http://www.cfug.org/infocom/
EXTRACT_SUFX=		.zip

MAINTAINER=		mph@freebsd.org

BUILD_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-qq

NO_WRKSUBDIR=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jzip ${PREFIX}/bin

.include <bsd.port.mk>
