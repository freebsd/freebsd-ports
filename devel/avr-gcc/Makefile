# New ports collection makefile for:	avr-gcc
# Date created:		29 Nov 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	3.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITES+=	http://people.freebsd.org/~joerg/:local
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	avr-
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX} \
		${MAN_AUX}:local
EXTRACT_ONLY=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joerg@freebsd.org
COMMENT=	FSF GCC 3.3.1 for Atmel AVR 8-bit RISC cross-development

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		autoheader:${PORTSDIR}/devel/autoconf \
		gettext:${PORTSDIR}/devel/gettext-old
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils

WRKSRC=		${WRKDIR}/gcc-${PORTVERSION}

# Unfortunately, only some mirrors have it as a .bz2 file, while
# the original master site still uses .gz.
USE_PERL5_BUILD=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--target=avr

MAN_AUX=	gcc-man.2003.09.09.tar.gz

MAKE_FLAGS=	LANGUAGES="c c++"
# get rid of that silly -mcpu=pentiumpro -current is so fond of. :-(
MAKE_ENV=	MACHINE_ARCH=avr

MAN1=		cpp.1 avr-gcc.1 avr-g++.1 gcov.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp gcc gccint cppinternals

# Since the pod2man in FreeBSD 4-stable's /usr/bin cannot be used, we
# help out by extracting precompiled manpages there.
pre-build:
		if perl -e 'use 1.10 Pod::Man' >/dev/null 2>/dev/null ; \
		then : ; \
		else \
			cd ${WRKDIR}/gcc-${PORTVERSION} ; \
			${TAR} -xvzf ${DISTDIR}/${MAN_AUX} ; \
		fi

.include <bsd.port.mk>
