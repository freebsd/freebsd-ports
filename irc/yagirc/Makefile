# New ports collection makefile for:   	yagirc
# Date created:				6 July 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	yagirc
PORTVERSION=	0.66.1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mph

MAINTAINER=	mph@freebsd.org

USE_XPM=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_IMLIB=	yes
USE_ESOUND=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-gnome --disable-pthread
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
