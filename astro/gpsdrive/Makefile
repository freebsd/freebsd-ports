# New ports collection makefile for:	gpsdrive
# Date Created:				16 April 2002
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	gpsdrive
PORTVERSION=	1.26.r4
CATEGORIES=	astro
MASTER_SITES=	http://gpsdrive.kraftvoll.at/ \
		http://gpsdrive.teachlinux.com/ \
		http://gpsdrive.flugfunk.de/ \
		http://gpsdrive.alumnosfdi.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/pre/}

MAINTAINER=	molter@gufi.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
BUILD_DEPENDS=	${X11BASE}/bin/gdk-pixbuf-config:${PORTSDIR}/graphics/gdk-pixbuf

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-debug \
			--disable-garmin
INSTALLS_SHLIB=	yes

MAN1=		gpsdrive.1
MANLANG=	"" de es

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.mk>
