# New ports collection makefile for:	gpsdrive
# Date Created:				16 April 2002
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	gpsdrive
PORTVERSION=	2.07.r7
CATEGORIES=	astro
MASTER_SITES=	http://gpsdrive.kraftvoll.at/     \
		http://www.gpsdrive.cc/           \
		http://www.kraftvoll.at/          \
		http://www.ganter.at/             \
		http://www.gpsdrive.de/           \
		http://gpsdrive.teachlinux.com/   \
		http://gpsdrive.flugfunk.de/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/pre/}

MAINTAINER=	molter@gufi.org
COMMENT=	A GPS navigation system

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GETOPT_LONG=yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_LIBTOOL=	yes
USE_GCC=	3.2
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-garmin --disable-mysql
INSTALLS_SHLIB=	yes

MAN1=		gpsdrive.1
MANLANG=	"" de es

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
