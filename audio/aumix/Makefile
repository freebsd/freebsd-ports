# New ports collection makefile for:	aumix
# Version required:    1.21
# Date created:        21 May 1999
# Whom:                Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.2 1999/06/02 05:26:34 mharo Exp $
#

DISTNAME=	aumix-1.21
CATEGORIES=	audio
MASTER_SITES=	http://jpj.net/~trevor/aumix/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=    intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib"
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

MAN1=	aumix.1

.include <bsd.port.mk>
