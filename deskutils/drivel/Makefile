# New ports collection makefile for:	drivel
# Date created:			Thu Feb 26 23:13:12 CET 2004
# Whom:				Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	drivel
PORTVERSION=	1.2.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	The Gnome livejournal client

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui intlhack
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
