# New ports collection makefile for:	aumix
# Version required:    1.27.1
# Date created:        21 May 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	aumix-1.27.3
CATEGORIES=	audio
MASTER_SITES=	http://jpj.net/~trevor/aumix/ \
		http://jpj.net/~trevor/aumix/old/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=    intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib"
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

MAN1=	aumix.1

.include <bsd.port.mk>
