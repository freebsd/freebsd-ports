# Ports collection makefile for:    setiathome
# Date created:         22 Apr 1999
# Whom:                 stb@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	setiathome
PORTVERSION=	1.2
CATEGORIES=	astro
MASTER_SITES=   http://setiathome.ssl.berkeley.edu/software/ \
		ftp://ftp.cdrom.com/pub/setiathome/ \
		http://people.FreeBSD.org/~stb/mirror/setiathome.ssl.berkeley.edu/software/

MAINTAINER=	stb@freebsd.org

ONLY_FOR_ARCHS=	i386

EXTRACT_CMD=		tar
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=

MAN1=		setiathome.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400000
PORTVERSION=	1.1
DISTFILES=      setiathome-1.1.i386-unknown-freebsd4.0.tar
WRKSRC=         setiathome-1.1.i386-unknown-freebsd4.0
.elif ${OSVERSION} >= 320000
DISTFILES=      setiathome-1.2.i386-unknown-freebsd3.2.tar
WRKSRC=         setiathome-1.2.i386-unknown-freebsd3.2
.elif ${OSVERSION} >= 310000
DISTFILES=      setiathome-1.2.i386-unknown-freebsd3.1.tar
WRKSRC=         setiathome-1.2.i386-unknown-freebsd3.1
.elif ${OSVERSION} >= 228000
DISTFILES=      setiathome-1.2.i386-unknown-freebsd2.2.8.tar
WRKSRC=         setiathome-1.2.i386-unknown-freebsd2.2.8
.elif ${OSVERSION} >= 227000
DISTFILES=      setiathome-1.2.i386-unknown-freebsd2.2.7.tar
WRKSRC=         setiathome-1.2.i386-unknown-freebsd2.2.7
.elif ${OSVERSION} >= 226000
DISTFILES=      setiathome-1.2.i386-unknown-freebsd2.2.6.tar
WRKSRC=         setiathome-1.2.i386-unknown-freebsd2.2.6
.else
DISTFILES=
.endif

.if make(makesum) || defined(FETCH_ALL)
DISTFILES=	setiathome-1.2.i386-unknown-freebsd2.2.6.tar	\
			setiathome-1.2.i386-unknown-freebsd2.2.7.tar	\
			setiathome-1.2.i386-unknown-freebsd2.2.8.tar	\
			setiathome-1.2.i386-unknown-freebsd3.1.tar	\
			setiathome-1.2.i386-unknown-freebsd3.2.tar	\
			setiathome-1.1.i386-unknown-freebsd4.0.tar
.endif

NO_BUILD=	"binary distribution"

MAN1=		setiathome.1

NO_CDROM=	"interactive install"

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

pre-fetch:
	@if [ -z "${DISTFILES}" ]; then \
		${ECHO} "It seems you are running FreeBSD `uname -r`, which is not currently";	\
		${ECHO} "supported.  SETI@home currently supports only FreeBSD 2.2.6 and above,";	\
		${ECHO} "FreeBSD 3.1. and above, and FreeBSD 4.0."; \
		${ECHO} \
		exit 72; \
	fi;

do-install:
	${INSTALL_PROGRAM}	${WRKDIR}/${WRKSRC}/setiathome ${PREFIX}/bin
	${INSTALL_SCRIPT}	${FILESDIR}/setiathome.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN}		${FILESDIR}/setiathome.1 ${MAN1PREFIX}/man/man1

post-install:
	@PKG_PREFIX=${PREFIX} PACKAGE_BUILDING=${PACKAGE_BUILDING} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
