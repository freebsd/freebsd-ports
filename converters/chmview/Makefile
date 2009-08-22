# New ports collection makefile for:	chmview
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	chmview
DISTVERSION=	2.0b3
CATEGORIES=	converters textproc
MASTER_SITES=	SF/trexinc/CHMView/2.0%20beta%203
DISTNAME=	CHMView_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extractor from .chm files

USE_ZIP=	yes
USE_DOS2UNIX=	yes

WRKSRC=		${WRKDIR}/src
PLIST_FILES=	bin/chmview

ONLY_FOR_ARCHS=	i386 amd64

pre-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/chmview ${PREFIX}/bin/

.include <bsd.port.mk>
