# New ports collection makefile for:	gpsdrive
# Date Created:				16 April 2002
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	gpsdrive
PORTVERSION=	1.31
CATEGORIES=	astro
MASTER_SITES=	http://gpsdrive.kraftvoll.at/     \
		http://gpsdrive.dotdeguy.de/      \
		http://gpsdrive.spoiledmeat.net/  \
		http://gpsdrive.flugfunk.de/      \
		http://gpsdrive.alumnosfdi.org/   \
		http://gpsdrive.teachlinux.com/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/pre/}

MAINTAINER=	molter@gufi.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gdkpixbuf
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-garmin --disable-mysql
INSTALLS_SHLIB=	yes

MAN1=		gpsdrive.1
MANLANG=	"" de es

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
