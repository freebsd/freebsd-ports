# New ports collection makefile for:	premake
# Date created:		2004-03-25
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	premake
PORTVERSION=	1.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	premake
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ahze@ahze.net
COMMENT=	Writes build scripts

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/Premake-${PORTVERSION}
USE_GMAKE=	yes
PLIST_FILES=	bin/premake
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
	@${INSTALL} ${WRKSRC}/premake ${PREFIX}/bin

.include <bsd.port.mk>
