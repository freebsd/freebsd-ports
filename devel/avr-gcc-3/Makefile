# New ports collection makefile for:	avr-gcc
# Date created:		29 Nov 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

SNAPDATE=	2001-03-20
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	gcc
PORTVERSION=	${SNAPVER}
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_GNU}
#MASTER_SITE_SUBDIR=	gcc
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/sourceware/gcc/snapshots/${SNAPDATE}/  \
		ftp://egcs.cygnus.com/pub/egcs/snapshots/${SNAPDATE}/  \
		ftp://ftp.ninemoons.com/pub/mirrors/egcs/snapshots/${SNAPDATE}/ \
		ftp://ftp.iij.ad.jp/pub/egcs/snapshots/${SNAPDATE}/ \
		ftp://ftp.yggdrasil.com/mirrors/site/egcs.cygnus.com/pub/egcs/snapshots/${SNAPDATE}/  \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/snapshots/
PKGNAMEPREFIX=	avr-
DISTNAME=	gcc-core-${PORTVERSION}

MAINTAINER=	joerg@freebsd.org

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		autoheader:${PORTSDIR}/devel/autoconf
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils

WRKSRC=		${WRKDIR}/gcc-${PORTVERSION}

# Unfortunately, only some mirrors have it as a .bz2 file, while
# the original master site still uses .gz.
#USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--target=avr

MAKE_FLAGS=	LANGUAGES="c"

MAN1=		cpp.1 avr-gcc.1 gcov.1

.include <bsd.port.mk>
