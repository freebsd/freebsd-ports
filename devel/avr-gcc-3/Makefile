# New ports collection makefile for:	avr-gcc
# Date created:		29 Nov 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	avr-
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX}

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
USE_BISON=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--target=avr

MAKE_FLAGS=	LANGUAGES="c c++"

MAN1=		cpp.1 avr-gcc.1 gcov.1

.include <bsd.port.mk>
