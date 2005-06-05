# New ports collection makefile for:	premake
# Date created:		2004-03-25
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	premake
PORTVERSION=	2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Writes build scripts

WRKSRC=		${WRKDIR}/Premake-${PORTVERSION}

USE_ZIP=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/premake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/premake ${PREFIX}/bin

.include <bsd.port.mk>
