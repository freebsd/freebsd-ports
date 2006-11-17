# New ports collection makefile for:	xanalyser
# Date created:				October 29 2006
# Whom:					Diane Bruce <db@db.net
#
# $FreeBSD$
#

PORTNAME=	xanalyser
PORTVERSION=	1.29
CATEGORIES=	audio hamradio
MASTER_SITES=	http://arvin.schnell-web.net/xanalyser/

MAINTAINER=	db@db.net
COMMENT=	Spectrum analyser

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_MOTIF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
MAN1=		xanalyser.1
PLIST_FILES=	bin/xanalyser \
		lib/X11/app-defaults/XAnalyser

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
BROKEN= Does not compile
.endif
.include <bsd.port.post.mk>
