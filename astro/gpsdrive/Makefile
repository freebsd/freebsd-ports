# New ports collection makefile for:	gpsdrive
# Date Created:				16 April 2002
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	gpsdrive
PORTVERSION=	2.09
PORTREVISION=	3
CATEGORIES=	astro
MASTER_SITES=	http://www.gpsdrive.cc/           \
		http://www.gpsdrive.oc512.us/     \
		http://gpsdrive.teachlinux.com/   \
		http://gpsdrive.flugfunk.de/

MAINTAINER=	molter@gufi.org
COMMENT=	A GPS navigation system

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

BROKEN=		Incomplete pkg-plist

USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_INC_LIBTOOL_VER=	13

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-garmin
INSTALLS_SHLIB=	yes

MAN1=		gpsdrive.1
MANLANG=	"" de es

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
