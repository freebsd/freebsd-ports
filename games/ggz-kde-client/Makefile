# New ports collection makefile for:	ggz-kde-client
# Date created:				Feb. 19, 2006
# Whom:					yinjieh
#
# $FreeBSD$
#

PORTNAME=	ggz-kde-client
PORTVERSION=	0.0.12
CATEGORIES=	games
MASTER_SITES=	http://mirrors.dotsrc.org/ggzgamingzone/ggz/%SUBDIR%/ \
		http://ftp.ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - KDE Client

LIB_DEPENDS=	ggzcore.8:${PORTSDIR}/games/ggz-client-libs

BROKEN=		Incomplete pkg-plist

GNU_CONFIGURE=	yes
USE_GCC=	3.3+
USE_GMAKE=	yes
USE_KDELIBS_VER=	3

MAN6=		compcal.6 ggzap.6 keepalivecontrol.6 \
		kggz.6 kgrubby.6 shadowbridge.6

.include <bsd.port.mk>
