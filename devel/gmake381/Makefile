# New ports collection makefile for:	GNU make
# Date created:		11 September 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	gmake
PORTVERSION=	3.79.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	make
DISTNAME=	make-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g \
		--with-included-gettext
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_LOCALE_H -DHAVE_LC_MESSAGES" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gmake.1

.ifdef USE_GMAKE
.error You have `USE_GMAKE' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

# joerg@freebsd.org says our getloadavg() no longer requires setgid kmem

post-install:
	${CHMOD} g-s ${PREFIX}/bin/gmake
	chgrp ${BINGRP} ${PREFIX}/bin/gmake

.include <bsd.port.mk>
