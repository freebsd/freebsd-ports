# New ports collection makefile for:	gpsdrive
# Date Created:				16 April 2002
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	gpsdrive
PORTVERSION=	2.07.r7
PORTREVISION=	2
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

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_LIBTOOL_VER=	13

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-garmin --disable-mysql
INSTALLS_SHLIB=	yes

MAN1=		gpsdrive.1
MANLANG=	"" de es

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501103 && ${OSVERSION} >= 500000
USE_GCC=3.2
.else
USE_GCC=3.3
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
