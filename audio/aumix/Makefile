# New ports collection makefile for:	aumix
# Version required:    1.18.4
# Date created:        21 May 1999
# Whom:                Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	aumix-1.18.4
CATEGORIES=	audio
MASTER_SITES=	http://jpj.net/~trevor/aumix/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=    intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-L${LOCALBASE}/lib -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -I${LOCALBASE}/include"

MAN1=	aumix.1

.include <bsd.port.mk>
