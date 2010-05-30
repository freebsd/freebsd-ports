# New ports collection Makefile for: moon-buggy
# Date created:		10 January 2002
# Whom:			Ralf Becker <ralf@akk.org>
#
# $FreeBSD$
#

PORTNAME=	moon-buggy
PORTVERSION=	1.0.51
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://seehuhn.de/media/programs/
.if defined (WITH_ESOUND)
PKGNAMESUFFIX=	"-esound"
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-sound-${PORTVERSION}${EXTRACT_SUFX}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.ac
.endif

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Drive a buggy across the moons surface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.if defined (WITH_ESOUND)
LIB_DEPENDS=	esd:${PORTSDIR}/audio/esound:install
.endif

USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--sharedstatedir=/var/games\
		--with-setgid=games

MAN6=		moon-buggy.6
INFO=		moon-buggy

PLIST_FILES=	bin/moon-buggy
.if defined (WITH_ESOUND)
PLIST_FILES+=	share/moon-buggy/jump.wav \
		share/moon-buggy/laser.wav \
		share/moon-buggy/crash.wav
PLIST_DIRS+=	share/moon-buggy

pre-patch:
	cd ${WRKSRC} && ${PATCH} -p1 < sound.patch
.endif

# make package will fail without doing this
post-install:
	${CHMOD} 0555 ${PREFIX}/bin/moon-buggy

.include <bsd.port.mk>
