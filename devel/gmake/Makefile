# New ports collection makefile for:	GNU make
# Date created:		11 September 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	gmake
PORTVERSION=	3.79.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	make
DISTNAME=	make-${PORTVERSION}

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_LOCALE_H" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gmake.1

# joerg@freebsd.org says our getloadavg() no longer requires setgid kmem

post-install:
	${CHMOD} g-s ${PREFIX}/bin/gmake
	chgrp ${BINGRP} ${PREFIX}/bin/gmake

.include <bsd.port.mk>
