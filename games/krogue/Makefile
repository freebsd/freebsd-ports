# New ports collection makefile for:	krogue
# Version required:	0.9.6
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	krogue-0.9.6
CATEGORIES=	games
MASTER_SITES=	http://ksi.ii.uj.edu.pl/krogue/dl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV=	SHELL=${SH} PREFIX=${PREFIX} MAKE=${GMAKE} PCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
