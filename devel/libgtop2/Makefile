# New ports collection makefile for:	libgtop2
# Date Created:			29 April 2002
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtop2
PORTVERSION=	2.0.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.0
DISTNAME=	libgtop-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	glib-2.0.0:${PORTSDIR}/devel/glib20

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-install:
	install-info --section="Programming \& development tools" \
	--entry="* libgtop2: (libgtop2).	libgtop2 programming manual" \
	${PREFIX}/info/libgtop2.info ${PREFIX}/info/dir
	@${CHGRP} kmem ${PREFIX}/bin/libgtop_server2
	@${CHMOD} 2555 ${PREFIX}/bin/libgtop_server2

.include <bsd.port.mk>
