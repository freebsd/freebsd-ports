# New ports collection makefile for:	ida
# Date created:				Thu Aug 19 21:13:58 UTC 2004
# Whom:					Andrey Slusar <anray@inet.ua>
#
# $FreeBSD$
#

PORTNAME=	ida
PORTVERSION=	0.21
CATEGORIES=	graphics
MASTER_SITES=	http://dl.bytesex.org/releases/fbida/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	anray@inet.ua
COMMENT=	Small and fast motif-based image viewer and editor

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_MOTIF=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
MAKEFILE=	${WRKSRC}/GNUmakefile

MAN1=		ida.1
PORTDOCS=	README TODO INSTALL

PLIST_FILES=	bin/ida lib/X11/app-defaults/Ida

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|PRId32|"d"|g' -e 's|PRIx32|"x"|g' \
		${WRKSRC}/tiff.c ${WRKSRC}/xwd.c
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for a in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
