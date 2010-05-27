# New ports collection makefile for:	xanalyser
# Date created:				October 29 2006
# Whom:					Diane Bruce <db@db.net
#
# $FreeBSD$
#

PORTNAME=	xanalyser
PORTVERSION=	1.32
CATEGORIES=	audio hamradio
MASTER_SITES=	http://arvin.schnell-web.net/xanalyser/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Spectrum analyser

USE_BZIP2=	yes
USE_MOTIF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
MAN1=		xanalyser.1
PLIST_FILES=	bin/xanalyser \
		lib/X11/app-defaults/XAnalyser

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%MOTIFLIB%%|${MOTIFLIB} |g' \
	    -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/xanalyser.spec ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
