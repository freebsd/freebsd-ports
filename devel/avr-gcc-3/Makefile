# New ports collection makefile for:	avr-gcc
# Date created:		29 Nov 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcc
PKGNAMEPREFIX=	avr-
DISTNAME=	gcc-core-${PORTVERSION}

PATCH_SITES=	http://home.overta.ru/users/denisc/gcc/
PATCHFILES=	${DISTNAME}-avr-patch-1.1.gz
PATCH_DIST_STRIP=	-p1

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
CONFIGURE_ENV=	CFLAGS="-O -pipe"

MAKE_FLAGS=	LANGUAGES="c"

MAN1=		cccp.1 avr-gcc.1

.include <bsd.port.mk>
