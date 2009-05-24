# New ports collection makefile for:	ida
# Date created:				Thu Aug 19 21:13:58 UTC 2004
# Whom:					Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ida
PORTVERSION=	2.07
CATEGORIES=	graphics
MASTER_SITES=	http://dl.bytesex.org/releases/fbida/
DISTNAME=	fbida-${PORTVERSION}

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Small and fast motif-based image viewer and editor

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		exif.12:${PORTSDIR}/graphics/libexif

USE_GMAKE=	yes
USE_MOTIF=	yes
USE_PERL5_BUILD=yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
MAKEFILE=	${WRKSRC}/GNUmakefile

MAN1=		exiftran.1 ida.1
PORTDOCS=	README TODO INSTALL

PLIST_FILES=	bin/exiftran bin/ida lib/X11/app-defaults/Ida

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exiftran ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for a in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
