# New ports collection makefile for:	xjump
# Date created:				Sun 25 Feb 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	xjump
PORTVERSION=	2.7.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple X game where one tries to jump up as many levels as possible

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/g}

PLIST_FILES=	bin/xjump
USE_X_PREFIX=	yes
USE_XPM=	yes
MAKE_ARGS=	CC="${CC} ${CFLAGS}" RECORD_FILE="/var/games/xjump.record" \
		IDIR="-I${X11BASE}/include" LDIR="-L${X11BASE}/lib"
ALL_TARGET=	xjump

do-install:
	${INSTALL_PROGRAM} -m 2755 -g games ${WRKSRC}/xjump ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
