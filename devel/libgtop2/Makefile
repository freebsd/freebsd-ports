# New ports collection makefile for:	libgtop2
# Date Created:			29 April 2002
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtop2
PORTVERSION=	2.0.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.0
DISTNAME=	libgtop-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 top library

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	install-info --section="Programming \& development tools" \
	--entry="* libgtop2: (libgtop2).	libgtop2 programming manual" \
	${PREFIX}/info/libgtop2.info ${PREFIX}/info/dir
	@${CHGRP} kmem ${PREFIX}/bin/libgtop_server2
	@${CHMOD} 2555 ${PREFIX}/bin/libgtop_server2

.include <bsd.port.mk>
