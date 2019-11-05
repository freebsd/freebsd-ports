# Created by: Matthew Hunt <mph@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xzip
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/infocom/interpreters/zip/ \
		http://www.ifarchive.org/if-archive/infocom/interpreters/zip/ \
		http://www.eblong.com/zarf/ftp/
DISTNAME=	xzip182
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infocom game interpreter that runs under X11

USES=		xorg
USE_XORG=	x11
WRKSRC=		${WRKDIR}/xzip
ALL_TARGET=

PLIST_FILES=	bin/xzip man/man1/xzip.1.gz

.include <bsd.port.mk>
