# New ports collection makefile for:	avr-gcc
# Date created:		29 Nov 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	3.3.2002.09.01
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_GNU}
#MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-${PORTVERSION}
#MASTER_SITES=	ftp://gcc.gnu.org/pub/gcc/snapshots/${PORTVERSION}/
MASTER_SITES=	http://people.freebsd.org/~joerg/
PKGNAMEPREFIX=	avr-
DISTFILES=	gcc-core+g++-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joerg@freebsd.org

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		autoheader:${PORTSDIR}/devel/autoconf
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils

WRKSRC=		${WRKDIR}/gcc-${PORTVERSION}

# Unfortunately, only some mirrors have it as a .bz2 file, while
# the original master site still uses .gz.
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--target=avr

MAKE_FLAGS=	LANGUAGES="c c++"

MAN1=		cpp.1 avr-gcc.1 avr-g++.1 gcov.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7

.include <bsd.port.mk>
