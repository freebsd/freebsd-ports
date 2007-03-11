# New ports collection makefile for:	chmview
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	chmview
DISTVERSION=	2.0b3
CATEGORIES=	converters textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	trexinc
DISTNAME=	CHMView_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extractor from .chm files

USE_ZIP=	yes
USE_DOS2UNIX=	yes

WRKSRC=		${WRKDIR}/src
PLIST_FILES=	bin/chmview

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		is not 64-bit clean
.endif

pre-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/chmview ${PREFIX}/bin/

.include <bsd.port.post.mk>
